#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "include/curl/curl.h"
#include "game.h"

#define IP "127.0.0.1"
#define PORT "2137"
#define API_PATH IP ":" PORT "/api?"

// curl data receive callback
static size_t writeFunc(void *contents, size_t size, size_t nmemb, void *data) {
	std::string *str = (std::string *)data;
	size_t realsize = size * nmemb;
	str->append((char *)contents, realsize);
	return realsize;
}

// helper for sending and receiving stuff
static bool makeRequest(CURL *curl, std::string request, std::string *response) {
	request = API_PATH + request;

	curl_easy_setopt(curl, CURLOPT_URL, request.data());;
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);
	
	CURLcode c = curl_easy_perform(curl);
	if (c != CURLE_OK) {
		std::cerr << curl_easy_strerror(c) << std::endl; // this is just debug
		return false;
	}

	return true;
}
	


// library functions

bool initialize() {
	// TODO: do we need to initialize everything? propably not.
	return curl_global_init(CURL_GLOBAL_ALL) == CURLE_OK;
}

int login(const char *usrname, const char *passwd, Session *sess) {
	std::stringstream request_url_ss;
	std::string response;

	sess->curl = curl_easy_init();
	if (sess->curl == NULL)
		return -1;
	curl_easy_setopt(sess->curl, CURLOPT_WRITEFUNCTION, writeFunc);

	request_url_ss << "command=login&nick=" << usrname << "&password=" << passwd;

	if (!makeRequest(sess->curl, request_url_ss.str(), &response))
		return -1;

	int status;
	int len;

	sscanf(response.data(), "{\"Status\":%d%n", &status, &len);
	if (status == 0)
		sscanf(response.data() + len, ",\"Id\":%d,\"Token\":\"%[^\"]\"}", &sess->my_id, sess->token);

	return status;
}

int getPlayerGames(Session sess, int player_id, std::vector<int> *game_ids) {
	std::stringstream request_url_ss;
	std::string response;

	request_url_ss << "command=getPlayerGames&playerId=" << player_id;

	if (!makeRequest(sess.curl, request_url_ss.str(), &response))
		return -1;

	int status;
	int len;

	sscanf(response.data(), "{\"Status\":%d%n", &status, &len);
	if (status == 0) {
		game_ids->clear();

		int l;
		sscanf(response.data() + len, ",\"Games\":[%n", &l);
		len += l;

		int g_id;
		if (sscanf(response.data() + len, "%d%n", &g_id, &l) == 1) {
			len += l;
			game_ids->push_back(g_id);
			while (sscanf(response.data() + len, ",%d%n", &g_id, &l) == 1) {
				len += l;
				game_ids->push_back(g_id);
			}
		}
	}

	return status;
}

int getMyStats(Session sess, int game_id, PlayerStats *stats) {
	std::stringstream request_url_ss;
	std::string response;

	request_url_ss << "command=getMyStats&token=" << sess.token << "&gameId=" << game_id;

	if (!makeRequest(sess.curl, request_url_ss.str(), &response))
		return -1;

	int status;
	int len;

	sscanf(response.data(), "{\"Status\":%d%n", &status, &len);

	if (status == 0) {
		int on_ground;
		sscanf(response.data() + len,
				",\"X\":%f"
				",\"Y\":%f"
				",\"Z\":%f"
				",\"VX\":%f"
				",\"VY\":%f"
				",\"VZ\":%f"
				",\"Gcool\":%f"
				",\"Hcool\":%f"
				",\"OnGround\":%d",
				&stats->x,
				&stats->y,
				&stats->z,
				&stats->vx,
				&stats->vy,
				&stats->vz,
				&stats->grenade_cooldown,
				&stats->blackhole_cooldown,
				&on_ground);
		stats->on_ground = (on_ground != 0);
	}

	return status;
}

int getPlatforms(Session sess, int game_id, std::vector<Platform> *platforms) {
	std::stringstream request_url_ss;
	std::string response;

	request_url_ss << "command=getGameMap&token=" << sess.token << "&gameId=" << game_id;

	if (!makeRequest(sess.curl, request_url_ss.str(), &response))
		return -1;

	int status;
	int len;

	sscanf(response.data(), "{\"Status\":%d%n", &status, &len);

	if (status == 0) {
		platforms->clear();

		int l;
		sscanf(response.data() + len, ",\"Platforms\":[%n", &l);
		len += l;

		Platform plat;
		while (sscanf(response.data() + len,
				"{\"X\":%f"
				",\"Y\":%f"
				",\"Z\":%f"
				",\"Radius\":%f}%n", &plat.x, &plat.y, &plat.z, &plat.radius, &l) == 4) {

			len += l;
			platforms->push_back(plat);

			if (response[len] == ',')
				len++;
			else
				break;
		}
	}

	return status;
}

int getProjectiles(Session sess, int game_id, std::vector<Projectile> *projectiles) {
	std::stringstream request_url_ss;
	std::string response;

	request_url_ss << "command=getProjectiles&token=" << sess.token << "&gameId=" << game_id;

	if (!makeRequest(sess.curl, request_url_ss.str(), &response))
		return -1;

	int status;
	int len;

	sscanf(response.data(), "{\"Status\":%d%n", &status, &len);

	if (status == 0) {
		projectiles->clear();

		int l;
		sscanf(response.data() + len, ",\"Projectiles\":[%n", &l);
		len += l;

		Projectile proj;
		int type;
		while (sscanf(response.data() + len,
				"{\"X\":%f"
				",\"Y\":%f"
				",\"Z\":%f"
				"{\"VX\":%f"
				",\"VY\":%f"
				",\"VZ\":%f"
				",\"Type\":%d}%n", &proj.x, &proj.y, &proj.z, &proj.vx, &proj.vy, &proj.vz, &type, &l) == 7) {

			proj.type = (type == 0 ? GRENADE : BLACKHOLE);
			len += l;
			projectiles->push_back(proj);

			if (response[len] == ',')
				len++;
			else
				break;
		}
	}

	return status;
}

int getPlayers(Session sess, int game_id, std::vector<Player> *players) {
	std::stringstream request_url_ss;
	std::string response;

	request_url_ss << "command=getPlayers&token=" << sess.token << "&gameId=" << game_id;

	if (!makeRequest(sess.curl, request_url_ss.str(), &response))
		return -1;

	int status;
	int len;

	sscanf(response.data(), "{\"Status\":%d%n", &status, &len);

	if (status == 0) {
		players->clear();

		int l;
		sscanf(response.data() + len, ",\"Players\":[%n", &l);
		len += l;

		Player player;
		while (sscanf(response.data() + len,
				"{\"X\":%f"
				",\"Y\":%f"
				",\"Z\":%f"
				",\"VX\":%f"
				",\"VY\":%f"
				",\"VZ\":%f"
				",\"ID\":%d}%n", &player.x, &player.y, &player.z, &player.vx, &player.vy, &player.vz, &player.id, &l) == 7) {

			len += l;
			players->push_back(player);

			if (response[len] == ',')
				len++;
			else
				break;
		}
	}

	return status;
}

static const char *errors[] = {
	"Ok",                   // 0
	"Syntax error",         // 1
	"Too many requests",    // 3
	"Game doesn't exist",   // 5
	"Player not in game",   // 6
	"Invalid token",        // 8
};

const char *getError(int err) {
	if (err < 0)
		return "Server error";

	else if ((size_t)err >= sizeof(errors)/sizeof(errors[0]))
		return "";
	else
		return errors[err];
}

int stop(Session sess, int game_id) {
	std::stringstream request_url_ss;
	std::string response;

	request_url_ss << "command=stop&token=" << sess.token << "&gameId=" << game_id;

	if (!makeRequest(sess.curl, request_url_ss.str(), &response))
		return -1;

	int status;
	sscanf(response.data(), "{\"Status\":%d}", &status);

	return status;
}

int move(Session sess, int game_id, float vx, float vz) {
	std::stringstream request_url_ss;
	std::string response;

	request_url_ss << "command=move&dx=" << vx << "&dz=" << vz << 
		"&token=" << sess.token << "&gameId=" << game_id;

	if (!makeRequest(sess.curl, request_url_ss.str(), &response))
		return -1;

	int status;
	sscanf(response.data(), "{\"Status\":%d}", &status);

	return status;
}

int jump(Session sess, int game_id) {
	std::stringstream request_url_ss;
	std::string response;

	request_url_ss << "command=jump&token=" << sess.token << "&gameId=" << game_id;

	if (!makeRequest(sess.curl, request_url_ss.str(), &response))
		return -1;

	int status;
	sscanf(response.data(), "{\"Status\":%d}", &status);

	return status;
}

int shootGrenade(Session sess, int game_id, float vx, float vy, float vz, float time) {
	std::stringstream request_url_ss;
	std::string response;

	request_url_ss << "command=grenade" << 
		"&dx=" << vx << "&dy=" << vy << "&dz=" << vz << "&time=" << time <<
		"&token=" << sess.token << "&gameId=" << game_id;

	if (!makeRequest(sess.curl, request_url_ss.str(), &response))
		return -1;

	int status;
	sscanf(response.data(), "{\"Status\":%d}", &status);

	return status;
}

int shootBlackhole(Session sess, int game_id, float vx, float vy, float vz, float time) {
	std::stringstream request_url_ss;
	std::string response;

	request_url_ss << "command=blackHole" << 
		"&dx=" << vx << "&dy=" << vy << "&dz=" << vz << "&time=" << time <<
		"&token=" << sess.token << "&gameId=" << game_id;

	if (!makeRequest(sess.curl, request_url_ss.str(), &response))
		return -1;

	int status;
	sscanf(response.data(), "{\"Status\":%d}", &status);

	return status;
}

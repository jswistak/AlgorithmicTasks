#ifndef GAME_H
#define GAME_H

#include <vector>

#define TOKEN_LENGTH 64

struct Session {
	int my_id;
	char token[TOKEN_LENGTH + 1];
	void *curl;
};

enum ProjectileType {
	GRENADE,
	BLACKHOLE,
};

struct Platform {
	float x, y, z;
	float radius;
};

struct Projectile {
	float x, y, z;
	float vx, vy, vz;
	ProjectileType type;
};

struct Player {
	float x, y, z;
	float vx, vy, vz;
	int id;
};

struct PlayerStats {
	float x, y, z;
	float vx, vy, vz;
	bool on_ground;
	float grenade_cooldown;
	float blackhole_cooldown;
};

// initializing curl
bool initialize();

// logging in
int login(const char *usrname, const char *passwd, Session *sess);

// personal info
int getPlayerGames(Session sess, int player_id, std::vector<int> *game_ids);

int getMyStats(Session sess, int game_id, PlayerStats *stats);

// map info
int getPlatforms(Session sess, int game_id, std::vector<Platform> *platforms);

int getProjectiles(Session sess, int game_id, std::vector<Projectile> *projectiles); 

int getPlayers(Session sess, int game_id, std::vector<Player> *players);

// error info
const char *getError(int err);

// movement
int stop(Session sess, int game_id);

int move(Session sess, int game_id, float vx, float vz);

int jump(Session sess, int game_id);

// projectile shooting
int shootGrenade(Session sess, int game_id, float vx, float vy, float vz, float time);

int shootBlackhole(Session sess, int game_id, float vx, float vy, float vz, float time);

#endif

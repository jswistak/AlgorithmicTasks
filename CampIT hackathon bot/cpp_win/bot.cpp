#include <cstdio>
#include <cmath>
#include <vector>
#include <thread>
#include <chrono>
#include "game.h"

int main(int argc, char **argv) {
	if (argc != 3)
		return 1;

	Session sess;
	std::vector<int> my_games;

	if (login(argv[1], argv[2], &sess) != 0)
		return 1;

	while (true) {
		my_games.clear();
		getPlayerGames(sess, sess.my_id, &my_games);

		for (int g : my_games) {
			jump(sess, g);
		}
	}
}

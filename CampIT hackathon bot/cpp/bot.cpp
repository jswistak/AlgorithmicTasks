#include <cstdio>
#include <vector>
#include <thread>
#include <chrono>
#include "game.h"

#define TPS 60

// Example bot which jumps in all games

int main() {
	Session sess;
    //sess - id gry sess.token -token
	std::vector<int> my_games;
    
	if (login("name", "pass", &sess) != 0)
		return 1;
    
	while (true) {
		my_games.clear();
		getPlayerGames(sess, sess.my_id, &my_games);

        for (int g : my_games){
			jump(sess, g);
        }

		// This is for not spamming
        
        
		std::this_thread::sleep_for(std::chrono::milliseconds(1000 / TPS));
	}
}

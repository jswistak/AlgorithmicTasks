#include <cstdio>
#include <vector>
#include <thread>
#include <chrono>
#include "game.h"
#include <iostream>

#define TPS 60

const double EPS = 0.000003;
using namespace std;
// Example bot which jumps in all games
double kwdrt(double x){
    return x*x;
}

double absol(double x){
    return max(x,-x);
}

int main() {
    Session sess;
    //sess - id gry sess.token -token
    std::vector<int> my_games;
    
    if (login("null", "fugObj3ctsUseHaske1l", &sess) != 0)
        return 1;
    //////////////////
    int skoczylem;
    while (true) {
        my_games.clear();
        getPlayerGames(sess, sess.my_id, &my_games);
        
        for (int g : my_games){
            
            vector <Platform> platf;
            //jump(sess, g);
            //cout<<"C";
            PlayerStats ja;
            getMyStats(sess, g, &ja);
            //cout<<"ala"<<endl;
            //jesli jestesmy na platformie to idziemy do centrum i skaczemy
            if(!getPlatforms(sess, g, &platf)){
                for(int i = 0; i < platf.size(); i++){
                    if( absol(ja.y-platf[i].y) < EPS && kwdrt(ja.x - platf[i].x) + kwdrt(ja.z - platf[i].z) <= kwdrt(platf[i].radius) ){
                        //jestesmy na tej platformie
                        if(kwdrt(ja.x - platf[i].x) + kwdrt(ja.z - platf[i].z) < EPS){
                            continue;
                        }
                        move(sess, g, platf[i].x - ja.x , platf[i].z - ja.z);
                        
                    }
                    //jesli promien jest mniejszy od EPS to skaczemy
                    double EPS2 = 0.001;
                    if(platf[i].radius < EPS2){
                        stop(sess, g);
                    }
                    if(platf[i].radius < EPS2){
                        stop(sess, g);
                        jump(sess, g);
                        skoczylem = g;
                        
                        if(ja.grenade_cooldown == 0)
                            shootGrenade(sess, g, 0, -1, 0, EPS2*2);
                    }
                }
            }
            vector <Player> gracz;
            int zmienna;
            const double LAT = 0.004;
            //cout << zmienna << endl;
            
            if(ja.grenade_cooldown < EPS && ja.vy < 0 && ja.blackhole_cooldown<10.0){
                zmienna = shootGrenade(sess, g, 0, -1, 0, LAT);
                cout << zmienna << endl;
            }
            if(ja.blackhole_cooldown < EPS && ja.vy < 0 && ja.grenade_cooldown<1.1){
                shootBlackhole(sess, g, 0, -1, 0, LAT);
            }
            
        }
        
        // This is for not spamming
        
        
        std::this_thread::sleep_for(std::chrono::milliseconds(400 / TPS));
    }
}

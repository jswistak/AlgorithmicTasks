#include <iostream>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

unsigned long long ile, a, b, c;
unsigned long long x;
long long pierwsza[1000100];
int wierzcholkow = 1;
int tab[200][200][200];


long long odleglosc;

struct pol{
    int a;
    int b;
    int c;
    int dist;
};

int odl;
pol pom;

void sito(){
    
    for(int i = 2; i <= 1000; i++){
        if(pierwsza[i] == 0){
            for(int j = i * i; j <= 1000010; j+=i){
                pierwsza[j] = 1;
            }
        }
    }
    
}

int main() {
    pierwsza[0] = 1;
    pierwsza[1] = 1;
    sito();
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> ile;
    queue <pol> kol;
    
    for(int i = 0; i < ile; i++){
        for(int j = 0; j < ile; j++){
            for(int k = 0; k < ile; k++){
                
                cin >> tab[i][j][k];
                
                if(tab[i][j][k] == 0){
                    pom.a = i;
                    pom.b = j;
                    pom.c = k;
                    pom.dist = 0;
                    kol.push(pom);
                }
            }
        }
    }
    //DEB
    //cout << "\n\n\n\n\n";
    
    while(!kol.empty()){
        pom = kol.front();
        //DEB
        //cout << pom.a << " " << pom.b << " " << pom.c << "\n";
        
        kol.pop();
        pom.dist++;
        if(pom.a - 1 >= 0 && pierwsza[tab[pom.a - 1][pom.b][pom.c]] == 0){
            tab[pom.a - 1][pom.b][pom.c] = 1;//ustawiamy jako nie pierwsza aby nie odwiedzac wiecej
            pom.a--;
            kol.push(pom);
            pom.a++;
        }
        if(pom.b - 1 >= 0 && pierwsza[tab[pom.a][pom.b - 1][pom.c]] == 0){
            tab[pom.a][pom.b - 1][pom.c] = 1;//ustawiamy jako nie pierwsza aby nie odwiedzac wiecej
            pom.b--;
            kol.push(pom);
            pom.b++;
        }
        if(pom.c - 1 >= 0 && pierwsza[tab[pom.a][pom.b][pom.c - 1]] == 0){
            tab[pom.a][pom.b][pom.c - 1] = 1;//ustawiamy jako nie pierwsza aby nie odwiedzac wiecej
            pom.c--;
            kol.push(pom);
            pom.c++;
        }
        ///teraz sprawdzamy co z maksem
        if(pom.a + 1 < ile && pierwsza[tab[pom.a + 1][pom.b][pom.c]] == 0){
            tab[pom.a + 1][pom.b][pom.c] = 1;//ustawiamy jako nie pierwsza aby nie odwiedzac wiecej
            pom.a++;
            kol.push(pom);
            pom.a--;
        }
        if(pom.b + 1 < ile && pierwsza[tab[pom.a][pom.b + 1][pom.c]] == 0){
            tab[pom.a][pom.b + 1][pom.c] = 1;//ustawiamy jako nie pierwsza aby nie odwiedzac wiecej
            pom.b++;
            kol.push(pom);
            pom.b--;
        }
        if(pom.c + 1 < ile && pierwsza[tab[pom.a][pom.b][pom.c + 1]] == 0){
            tab[pom.a][pom.b][pom.c + 1] = 1;//ustawiamy jako nie pierwsza aby nie odwiedzac wiecej
            pom.c++;
            kol.push(pom);
            pom.c--;
        }
        a = pom.a;
        b = pom.b;
        c = pom.c;
        if(min(a, min(b, c)) == 0){
            cout << pom.dist;
            return 0;
        }
        else if(max(a, max(b, c)) == ile - 1){
            cout << pom.dist;
            return 0;
        }
    }
    
    //DEB
    //cout << "Nie udalo sie\n";
    cout << 0;
    //mamy zwykly graf i przechodzimy po nim aby znalezc wierzcholki
    //zwykly bfs z pamietaniem odleglosci
    
    
    
    
    
    return 0;
}

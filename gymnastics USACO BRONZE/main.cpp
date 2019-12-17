#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <utility>
using namespace std;

int ile;
int tab[30][30];
int x[30];
int wynik = 0;
int testow, krow;

map < pair<int,int>, int> zlicz;


int main(int argc, const char * argv[]) {
    cin.tie(0);
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    
    map < pair<int,int>, int>::iterator it;
    
    cin >> testow >> krow;
    
    for(int i = 0; i < krow; i++){
        cin >> x[i];
    }
    
    for(int i = 0; i < krow - 1; i++){
        
        for(int j = i + 1; j < krow; j++){
            zlicz[ make_pair(x[i], x[j]) ] = 1;
            //tab[x[i]][x[j]] = 1;
            //wynik++;
        }
    }
    
    for(int ala = 1; ala < testow; ala++){
        
        for(int i = 0; i < krow; i++){
            cin >> x[i];
        }
        
        for(int i = 0; i < krow - 1; i++){
            
            for(int j = i + 1; j < krow; j++){
                it = zlicz.find(make_pair(x[j],x[i]));
                if(it != zlicz.end()){
                    zlicz.erase(it);
                }
            }
        }
        
    }
    
    cout << zlicz.size();
    //wczytaj pary z pierwszego fora dodawaj na mape potem z kolejnych jesli istnieja usuwaj z mapy potem zlicz elementy na mapie DONE
    return 0;
}

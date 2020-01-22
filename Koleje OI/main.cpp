//Drzewo przedzial-przedzial
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int miast, miejsc, zgloszen;
int pocz, kon, ludzi, l, r, wart;

pair<int,int> tree[500000];


void dodaj(int l, int r, int wart){
    int lakt = 1;
    int rakt = 1;
    
    while(l != r){
        //////lewy
        if(l % 2 == 0){
            if(lakt == 0 && l + 1 != r){
                tree[l + 1].first += wart;
            }
        }
        if(l % 2 == 1){
            if(lakt == 1){
                tree[l].first += wart;
            }
            lakt = 0;
        }
        
        /////////prawy
        
        if(r % 2 == 0){
            if(rakt == 1){
                tree[r].first += wart;
            }
            rakt = 0;
        }
        if(r % 2 == 1){
            if(rakt == 0 && r - 1 != l){
                tree[r - 1].first += wart;
            }
        }
        
        l /= 2;
        r /= 2;
    }
    if(lakt == rakt && rakt == 1){
        lakt = 0;
        rakt = 0;
        tree[l].first += wart;
    }
    if(lakt == 1){
        tree[l * 2].first += wart;
    }
    if(rakt == 1){
        tree[r * 2 + 1].first += wart;
        
    }
}

void update(int l, int r){
    while(l != 1){
        //first dodano na przedziale
        //second max z dzieci
        l /= 2;
        r /= 2;
        tree[l].second = max(tree[l * 2].first + tree[l * 2].second, tree[l * 2 + 1].first + tree[l * 2 + 1].second);
        tree[r].second = max(tree[r * 2].first + tree[r * 2].second, tree[r * 2 + 1].first + tree[r * 2 + 1].second);
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> miast >> miejsc >> zgloszen;
    int pocz = 1;
    while(pocz < miast){
        pocz *= 2;
    }
    
    //pocz pierwszy indeks drzewa
    
    for(int i = 0; i < zgloszen; i++){
        cin >> l >> r >> ludzi;
        r--;
        
        dodaj(l + pocz - 1, r + pocz - 1, ludzi);
        update(l + pocz - 1, r + pocz - 1);
        
        if(tree[1].first + tree[1].second <= miejsc){
            cout << "T\n";
        }
        else{
            cout << "N\n";
            dodaj(l + pocz - 1, r + pocz - 1, -ludzi);
            update(l + pocz - 1, r + pocz - 1);
        }
    }
    
    /*
     //Wypisz drzewo
    for(int i = 1; i < 2 * pocz; i++){
        cout << i << " (" << tree[i].first  << "," << tree[i].second << ")\n";
    }*/
    return 0;
}

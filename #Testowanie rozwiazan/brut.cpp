//Drzewo przedzial-przedzial
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int miast, miejsc, zgloszen;
int pocz, kon, ludzi, l, r, wart;

long long tree[500000];
int nie;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    
    cin >> miast >> miejsc >> zgloszen;
    
    for(int i = 0; i < zgloszen; i++){
        cin >> l >> r >> ludzi;
        
        nie = 0;
        for(int i = l; i < r; i++){
            if(tree[i] + ludzi > miejsc){
                nie = 1;
            }
        }
        if(nie == 1){
            cout << "N\n";
        }
        else{
            for(int i = l; i < r; i++){
                tree[i] += ludzi;
            }
            cout << "T\n";
        }
        
    }
    
    
    return 0;
}


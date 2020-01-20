#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <cmath>

#define INF 100000000

using namespace std;

long long a;
int n;
double one = 1.0;
int wynik;
int x;

double tab[17];

long long pots(long long a, int pot){
    long long wynik = 1;
    while(pot > 0){
        if(m % 2 == 1) wynik *= a;
        a *= a;
        m /= 2;
    }
    return wynik;
}
int main(){
    tab[0] = 2;
    tab[1] = 3;
    tab[2] = 5;
    tab[3] = 7;
    tab[4] = 11;
    tab[5] = 13;
    tab[6] = 17;
    tab[7] = 19;
    tab[8] = 23;
    tab[9] = 29;
    tab[10] = 31;
    tab[11] = 37;
    tab[12] = 41;
    tab[13] = 43;
    tab[14] = 47;
    tab[15] = 53;
    tab[16] = 59;
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a;
        
        for(auto f: tab){
            //cout << f << " ";
            x = round(pow(a, (double)(one/f)));
            if(pots(x, f) == a){
                //cout<< "OK";
                wynik++;
                break;
            }
        }
        
    }
    cout<< wynik;
    return 0;
}

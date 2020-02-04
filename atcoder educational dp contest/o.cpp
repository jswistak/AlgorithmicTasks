#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <iomanip>




using namespace std;



using ll = long long;
const ll INF = 1e18L + 5;
const int mod = 1e9 + 7;

ll dp[2100000];// < 2^21
ll n;
int tab[40][40];

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> tab[i][j];
        }
    }
    
    dp[0] = 1;
    for(int mask = 0; mask < (1 << n) - 1; mask++){// 1 << n all possibilities
        int a = __builtin_popcount(mask);
        for(int b = 0; b < n; b++){
            if(tab[a][b] && !(mask & (1 << b))){
                int m2 = mask | (1 << b);
                
                dp[m2] += dp[mask];
                if(dp[m2] >= mod){
                    dp[m2] -= mod;
                }
                
            }
        }
    }
    
    
    cout << dp[(1 << n) - 1];
}


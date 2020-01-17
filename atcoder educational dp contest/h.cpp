#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>

#define INF 1000000005

using namespace std;

const long long MOD = 1000000007;

int n, m;
int tab[1020][1020];
int dp[1020][1020];
char ch;
long long socre;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
        
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ch;
            tab[i][j] = ch;
        }
        
        
    }
    
    dp[0][0] = 1;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            if(i > 0 && tab[i - 1][j] != '#'){
                dp[i][j] += dp[i - 1][j];
            }
            if(j > 0 && tab[i][j - 1] != '#'){
                dp[i][j] += dp[i][j - 1];
            }
            dp[i][j] %= MOD;
        }
    }
    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << dp[i][j] << " ";
        }cout << "\n";
    }*/
    cout << dp[n - 1][m - 1];
}


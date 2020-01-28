#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <iomanip>

#define INF 10000000000

using namespace std;

int n, k, x;

long long tab[3010];
long long dp[3010][3010];

void s(int a, int b){
    if(dp[a][b] == INF){
        if(a == b){
            dp[a][b] = tab[a];
        }
        else{
            s(a + 1, b);
            s(a, b - 1);
            dp[a][b] = max(tab[a] - dp[a + 1][b], tab[b] - dp[a][b - 1]);
            
        }
    }
    //return dp[a][b]
}
int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = INF;
        }
    }
    for(int i = 0; i < n; i++){
        cin >> tab[i];
    }
    
    s(0, n - 1);
    cout << dp[0][n - 1];
}



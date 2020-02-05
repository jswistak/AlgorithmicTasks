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

int n;
string cmp;
int dp[3010][3010];
int pref[3010][3010];
void add(int& a, int b){
    a += b;
    while(a >= mod){
        a -= mod;
    }
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    cin >> cmp;
    //dp[i][j] number of ways to put numbeers in prefix of size i such that the last one is j
    dp[1][1] = 1;
    int len = cmp.size();
    
    for(int len = 2; len <= n; len++){
        //pref on dp[len - 1]
        for(int i = 1; i <= len - 1; i++){
            pref[len - 1][i] = (pref[len - 1][i - 1] + dp[len -1][i]) % mod;
        }
        
        for(int b = 1; b <= len; b++){
            int L;
            int R;
            if(cmp[len - 2] == '<'){
                L = 1;
                R = b - 1;
            }
            else{
                L = b;
                R = len - 1;
            }
            if(L <= R){
                add(dp[len][b], pref[len - 1][R] - pref[len - 1][L - 1] + mod);
            }
        }
    }
    int answer = 0;
    for(int b = 1; b <= n; b++){
        add(answer, dp[n][b]);
    }
    
    cout << answer;
}


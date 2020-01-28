#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <iomanip>




using namespace std;



using ll = long long;
const ll INF = 1e18L + 5;
ll dp[500][500];
ll n;
ll tab[500];

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //dp[i][j] - cost to connect interval i to j
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tab[i];
    }
    auto sum = [&](int L, int R){
        ll s = 0;
        for(int i = L; i <= R; i++){
            s += tab[i];
        }
        return s;
    };
    for(int L = n - 1; L >= 0 ; L--){
        for(int R = L; R < n; R++){
            if(L == R){
                dp[L][R] = 0;
            }
            else{
                dp[L][R] = INF;
                ll s = sum(L, R);
                for(int i = L; i < R; i++){
                    dp[L][R] = min(dp[L][R], dp[L][i] + dp[i + 1][R] + s);
                }
            }
        }
    }
    
    
    cout << dp[0][n - 1];
}


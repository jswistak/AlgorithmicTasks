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
vector<ll> dp;
vector<ll> pre;
//pre[mask] score of group mask
void rec(int i, const vector<int>& notTaken, ll scoreSoFar, int mask, int group){
    if(i == (int) notTaken.size()){
        dp[mask] = max(dp[mask], scoreSoFar + pre[group]);
        return;
    }
    rec(i + 1, notTaken, scoreSoFar, mask, group);
    rec(i + 1, notTaken, scoreSoFar, mask ^ (1 << notTaken[i]), group ^ (1 << notTaken[i]));
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    vector<vector<ll>> in(n, vector<ll>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> in[i][j];
        }
    }
    pre.resize(1 << n);
    for(int mask = 0; mask < (1 << n); mask++){
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                for(int j = i + 1; j < n; j++){
                    if(mask & (1 << j)){
                        pre[mask] += in[i][j];
                    }
                }
            }
        }
    }
    //dp[maks] best total score if we grouped rabbits from mask already
    dp.resize(1 << n, -INF);
    dp[0] = 0;
    
    for(int mask = 0; mask < (1 << n); mask++){
        vector<int> notTaken;
        for(int i = 0; i < n; i++){
            if(!(mask & (1 << i))){
                notTaken.push_back(i);
            }
        }
        rec(0, notTaken, dp[mask], mask, 0);
    }
    
    cout << dp[(1 << n) - 1];
}


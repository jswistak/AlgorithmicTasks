#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <iomanip>


using namespace std;

using ll = long long;
const ll INF = 1e18L + 5;


struct S {
    int w, s, v;
    void read(){
        cin >> w >> s >> v;
    }
    bool operator < (const S&b) const{
        return w + s < b.w + b.s;
    }
};


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<S> in(n);
    int MAX_S = 20123;
    for(int i = 0; i < n; i++){
        in[i].read();
    }
    sort(in.begin(), in.end());
    vector<ll> dp(MAX_S + 1);
    //dp[i]  best score of boxes with total weight i
    for(S block : in){
        for(int w = min(block.s, MAX_S - block.w); w >= 0; w--){
            dp[w + block.w] = max(dp[w + block.w], dp[w] + block.v);
        }
    }
    ll answer = 0;
    for(int i = 0; i <= MAX_S; i++){
        answer = max(answer, dp[i]);
    }
    cout << answer;
}


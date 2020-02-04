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

int h[1000000];
ll a[1000000];
ll dp[1000000];
ll tree[1000000];
int n;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    int b = 1;
    while(b <= n){
        b *= 2;
    }
    
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    
    //dp[i] max total beauty so far if the last taken flower has height i
    
    for(int flower = 0; flower < n; flower++){
        int x = h[flower] + b;
        ll best = 0;
        while(x > 1){
            if(x % 2 == 1){
                best = max(best, tree[x - 1]);
            }
            x /= 2;
        }
        dp[h[flower]] = best + a[flower];
        for(int i = b + h[flower]; i >= 1; i /= 2){
            tree[i] = max(tree[i], dp[h[flower]]);
        }
    }
    ll ans = 0;
    for(int i = 0; i <= n; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

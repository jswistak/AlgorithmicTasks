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
const int nax  = 2e5 + 5;
int fac[nax], inv_fac[nax];

int mul(int a, int b){
    return (ll) a * b % mod;
}

int mpow(int a, int b){
    int r  = 1;
    while(b) {
        if(b % 2){
            r = mul(r, a);
        }
        a = mul(a, a);
        b /= 2;
    }
    return r;
}

int minv(int a){
    return mpow(a, mod - 2);
}

int binomial(int a, int b){
    if(a < 0 || b < 0 || b > a){
        return 0;
    }
    return mul(fac[a], mul(inv_fac[b], inv_fac[a - b]));
}

int f(int a, int b){
    int tmp = binomial(a + b, b);
    return tmp;
}

int sub(int a, int b){
    return (a - b + mod) % mod;
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    fac[0] = inv_fac[0] = 1;
    for(int i = 1; i < nax; i++){
        fac[i] = mul(fac[i - 1], i);
        inv_fac[i]  = minv(fac[i]);
    }
    int h, w, n;
    
    cin >> h >> w >> n;
    vector<pair<int, int>> in(n);
    for(int i = 0; i < n; i++){
        cin >> in[i].first >> in[i].second;
    }
    sort(in.begin(), in.end(), [&](pair<int, int> a, pair<int, int> b) {
        return a.first + a.second < b.first + b.second;
        
    });
    
    //dp[i] number of paths to vertex in[i]such that it's the first forbidden vertex
    
    in.emplace_back(h, w);
    
    vector<int> dp(n + 1);
    for(int i = 0; i <= n; i++){
        int tmp = f(in[i].first - 1, in[i].second - 1);
        
        for(int j = 0; j < i; j++) {
            if(in[j].first <= in[i].first && in[j].second <= in[i].second) {
                tmp = sub(tmp, mul(dp[j], f(in[i].first - in[j].first, in[i].second-in[j].second)));
            }
        }
        
        dp[i] = tmp;
    }
    cout << dp[n];
}


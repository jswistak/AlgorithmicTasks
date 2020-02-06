#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

using ll = long long;
const ll INF = 1e18L + 5;

struct Line {
    ll a, b;
    ll value(ll x){
        return a * x + b;
    }
    pair<ll, ll> inter(const Line& he) const {
        ll one = he.b - b;
        ll two = a - he.a;
        if(two < 0){
            one *= -1;
            two *= -1;
        }
        return {one, two};
    }
};

ll square(ll a){
    return a * a;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    ll C;
    cin >> n >> C;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    
    vector<Line> lines;
    int start = 0;
    for(int i = 0; i < n; i++){
        
        while(start <= (int) lines.size() - 2){
            Line A = lines[start];
            Line B = lines[start + 1];
            if(A.value(h[i]) >= B.value(h[i])){
                start++;
            }
            else{
                break;
            }
        }
        ll best = 0; //dp[i]
        if(i != 0){
            best = lines[start].value(h[i]) + square(h[i]) + C;
        }
        Line line{-2 * h[i], best + square(h[i])};
        
        while(start <= (int) lines.size() - 2){
            Line A = lines.end()[-2];
            Line B = lines.end()[-1];
            pair<ll, ll> one = A.inter(B);
            pair<ll, ll> two = B.inter(line);
            
            if((__int128) one.first * two.second >= (__int128) one.second * two.first){
                lines.pop_back();
            }
            else{
                break;
            }
        }
        lines.push_back(line);
        if(i == n - 1){
            cout << best;
        }
    }
    
    
}


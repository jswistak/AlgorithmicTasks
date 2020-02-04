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

void add(int&a, int b){
    a += b;
    if(a >= mod){
        a -= mod;
    }
}
int mul(int a, int b){
    return (ll) a * b % mod;
}

struct M{
    vector<vector<int>> t;
    M(){
        t.resize(n, vector<int>(n));
    }
    M operator* (const M& b) const{
        M c = M();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    add(c.t[i][k], mul(t[i][j], b.t[j][k]));
                }
            }
        }
        return c;
    }
};

int main(){
    
    ll k;
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> k;
    
    vector<vector<int>> can(n, vector<int>(n));
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> can[i][j];
        }
    }
    
    M answer = M();
    for(int i = 0; i < n; i++){
        answer.t[i][i] = 1;
    }
    M m = M();
    
    m.t = can;
    while (k) {
        if(k % 2){
            answer = answer * m;
        }
        m = m * m;
        k /= 2;
    }
    
    int total = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            add(total, answer.t[i][j]);
        }
    }
    cout << total;
    
}


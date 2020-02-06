#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <iomanip>


using namespace std;

using ll = long long;
const ll INF = 1e18L + 5;

const int nax = 2e5 + 5;

vector<pair<int, int>> intervals[nax];

struct S {
    ll small, lazy;
    void merge(const S& a, const S& b){
        small = min(a.small, b.small);
        
    }
    void add(ll x){
        small += x;
        lazy += x;
    }
};

vector<S> tree;

const int TYPE_ADD = 1, TYPE_MIN = 2;
void rec(int id, int low, int high, int qLow, int qHigh, int type, ll& x){
    if(high < qLow || qHigh < low){
        return;
    }
    if(qLow <= low && high <= qHigh){
        if(type == TYPE_ADD){
            tree[id].add(x);
        }
        else if(type = TYPE_MIN){
            x =  min(x, tree[id].small);
        }
        /////
        return;
    }
    for(int b : {2 * id, 2 * id + 1}){
        tree[b].add(tree[id].lazy);
    }
    tree[id].lazy = 0;
    
    int lastLeft = (low + high) / 2;
    rec(2 * id, low, lastLeft, qLow, qHigh, type, x);
    rec(2 * id + 1, lastLeft + 1, high, qLow, qHigh, type, x);
    
    tree[id].merge(tree[2 * id], tree[2 * id + 1]);
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    ll sum = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        intervals[b].emplace_back(a, c);
        sum += c;
    }
    
    ll answer = 0;
    
    int base = 1;
    while(base <= n + 1){
        base *= 2;
    }
    tree.resize(2 * base, {INF, 0});
    ll xd = -INF;
    rec(1, 0, base - 1, 0, 0, TYPE_ADD, xd);
    
    for(int i = 1; i <= n + 1; i++){
        for(pair<int, int> p : intervals[i - 1]){
            xd = p.second;
            rec(1, 0, base - 1, 0, p.first - 1, TYPE_ADD, xd);
        }
        ll best = INF;
        rec(1, 0, base - 1, 0, base - 1, TYPE_MIN, best);
        if(i == n + 1){
            answer = best;
        }
        xd = best - INF;
        rec(1, 0, base - 1, i, i, TYPE_ADD, xd);
    }
    cout << sum - answer << "\n";
    

}


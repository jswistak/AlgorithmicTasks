#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <iomanip>



using namespace std;

using ll = long long;
const ll INF = 1e18L + 5;

const int nax = 1e5 + 5;

int mod;
int n, a, b;

int add(int a, int b){
    return (a + b) % mod;
}
int mul(int a, int b){
    return (ll) a * b % mod;
}


vector<int> edges[nax], children[nax];
vector<pair<int, int>> downs[nax], pref[nax], suf[nax];
pair<int, int> down[nax], up[nax];

pair<int, int> merge(const pair<int, int>& a,const pair<int, int>& b){
    pair<int, int> p;
    p.first = mul(a.first, b.first);
    p.second =  add(mul(a.second, add(b.first, b.second)), mul(a.first, b.second));
    return p;
}

pair<int, int> process(pair<int,int> p){
    return {p.first, add(p.first, p.second)};
}


void dfsOne(int a, int parent){
    pair<int, int> p{1, 0};
    for(int b : edges[a]){
        if(b != parent){
            children[a].push_back(b);
            dfsOne(b, a);
            p = merge(p, down[b]);
            downs[a].push_back(down[b]);
        }
    }
    down[a] = process(p);
}

void dfsTwo(int a, int parent){
    for(int i = 0; i < children[a].size(); i++){
        pair<int, int> p{1, 0};
        if(i != 0){
            p = merge(p, pref[a][i -1]);
        }
        if(i != downs[a].size() - 1){
            p = merge(p, suf[a][i + 1]);
        }
        if(a != 1){
            p = merge(p, up[a]);
        }
        int b = children[a][i];
        up[b] = process(p);
        dfsTwo(b, a);
    }
}



int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> mod;
    
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfsOne(1, -1);
    for(int a = 1; a <= n; a++){
        int k = downs[a].size();
        pair<int, int> p{1, 0};
        for(int i = 0; i < k; i++){
            p = merge(p, downs[a][i]);
            pref[a].push_back(p);
        }
        p = {1, 0};
        for(int i = k - 1; i >= 0; i--){
            p = merge(p, downs[a][i]);
            suf[a].push_back(p);
        }
        reverse(suf[a].begin(), suf[a].end());
    }
    
    dfsTwo(1, -1);
    for(int a = 1; a <= n; a++){
        pair<int, int> p{1,0};
        if(a != 1){
            p = merge(p, up[a]);
        }
        if(!children[a].empty()){
            p = merge(p, pref[a].back());
        }
        p = process(p);
        cout << p.second << "\n";
    }
}

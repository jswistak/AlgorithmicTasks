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



vector<int> edge[1000000];
int a, b, n;

//first - black; second - white
pair<int,int> dfs(int a, int partent){
    long long allWhite = 1;//can be painted black
    long long sthBlack = 0;
    for(auto v : edge[a]){
        if(v != partent){
            pair<int, int> p = dfs(v, a);
            //p.first is the number of ways to color subtree such that v is black
            sthBlack = (allWhite * p.first) + (sthBlack * (p.first + p.second));
            sthBlack %= mod;
            allWhite = (allWhite * p.second) % mod;
        }
    }
    
    return make_pair(allWhite, (allWhite + sthBlack) % mod);
}

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    
    cin >> n;
    
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    
    
    pair<int,int> p = dfs(1, -1);
    
    cout << (p.first + p.second) % mod;
}


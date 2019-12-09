#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>

#define mp make_pair
#define f first
#define s second
#define pb push_back

using namespace std;
const int MXN = 1e3 + 5;
typedef pair<int,int> PI;
map<PI,vector<PI> > mapa;
int n, m, k, a, b, c, d;
bool odw[MXN][MXN];
int odl[MXN][MXN], max1, motyle;
PI skad;
void dfs(int x, int y, int dep){
    odw[x][y] = 1;
    odl[x][y] = dep;
    motyle++;
    vector<PI>pom = (mapa[mp(x, y)]);
    for(int i = 0; i < pom.size(); i++){
        PI curr = pom[i];
        if(odw[curr.f][curr.s] == 0){
            dfs(curr.f, curr.s, dep + 1);
        }
    }
}
void czysc(){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            odw[i][j] = 0;
            odl[i][j] = 0;
        }
    }
}
int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < n * m - 1; i++){
        cin >> a >> b >> c >> d;
        mapa[mp(a, b)].pb(mp(c, d));
        mapa[mp(c,d)].pb(mp(a, b));
    }
    dfs(1, 1, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(max1 < odl[i][j]){
                max1 = odl[i][j];
                skad = mp(i, j);
            }
        }
    }
    max1 = 0;
    motyle = 0;
    czysc();
    dfs(skad.f, skad.s, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(max1 < odl[i][j]){
                max1 = odl[i][j];
                skad = mp(i,j);
            }
        }
    }
    if(max1 == k && motyle == n * m){
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}

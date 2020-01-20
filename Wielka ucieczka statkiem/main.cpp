#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>

#define INF 10000000000

using namespace std;

int a, b, c;
int n, m;

vector< pair<long long, long long> > krawedz[1000000];
pair <long long, long long> x;
long long wynik[1000000];
long long wynik2[1000000];
int odw[1000000];
void DJIKSTRA(){
    
    priority_queue < pair<long long, long long> > q;
    q.push(make_pair(0, 1));//vertex 1 with cost 0
    
    while(q.size()){
        x = q.top();
        //x.first cost
        //x.second id
        q.pop();
        
        
        
        if(odw[x.second] > 1){
            continue;
        }
        odw[x.second]++;
        if(odw[x.second] == 1)
            wynik[x.second] = min(wynik[x.second], - x.first);
        if(odw[x.second] == 2)
            wynik2[x.second] = min(wynik2[x.second], - x.first);
        for(int i = 0; i < krawedz[x.second].size(); i++){
                q.push(make_pair((x.first - krawedz[x.second][i].first), krawedz[x.second][i].second));
        }
    }
    
    
    
}

int main(){
                
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i < 1000000; i++){
        wynik[i] = INF;
        wynik2[i] = INF;
    }
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        cin>> a >> b >> c;
        krawedz[a].push_back(make_pair(c, b));
        //krawedz[b].push_back(make_pair(c, a)); // bo zmienili tresc i skierowany -_-

    }
    //cout<<"a";
    //return 0;
    DJIKSTRA();
    
    /*
    
    for(int i = 1; i <= n; i++){
        cout << wynik[i] << " ";
    }cout << "\n\n";
    for(int i = 1; i <= n; i++){
        cout << wynik2[i] << " ";
    }
    cout << "\n\n";
    */
    
    if(wynik2[n] == INF){
        cout << -1;
    }
    else{
        cout << wynik2[n];
    }
    return 0;
}

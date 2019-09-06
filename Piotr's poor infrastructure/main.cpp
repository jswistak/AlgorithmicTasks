#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int getint(){
    char c;
    int temp = 0;
    do{
        c = getchar_unlocked();
    }while(c < '0' || c > '9');
    
    do{
        temp = temp * 10 + c - '0';
        c = getchar_unlocked();
    }while(c >= '0' && c <= '9');
    
    return temp;
    
}

int ile, a, b;
int dist[1000100];
int vis[1000100];
int FirstDist[1000100];
int SecondDist[1000100];
vector <int> edge[1000100];
int FirstCandidate, SecondCandidate;

int bfs(int start){
    vector < pair<int, int> > q;
    dist[start] = 1;
    q.push_back( make_pair(start, 1) );
    vis[start] = start;
    for(int i = 0; i < q.size(); i++){
        int w = q[i].first;
        dist[w] = q[i].second + 1;
        for(int j = 0; j <edge[w].size(); j++){
            if(vis[edge[w][j]] != start){
                q.push_back( make_pair(edge[w][j], dist[w]) );
                vis[edge[w][j]] = start;
                
            }
        }
    }
    int maks = 0;
    int najdalszy = 0;
    for(int i = 1; i <= ile; i++){
        if(maks < dist[i]){
            maks = dist[i];
            najdalszy=i;
        }
    }
    return najdalszy;
}

int main() {
    ile = getint();
    for(int i = 0; i < ile - 1; i++){
        a = getint();
        b = getint();
        
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    FirstCandidate = bfs(1);
    //FirstCandidate SecondCandidate najdalsze wierzcholki
    
    
    SecondCandidate = bfs(FirstCandidate);
    for(int i = 1; i <= ile; i++){
        FirstDist[i] = dist[i];
    }
    bfs(SecondCandidate);
    for(int i = 1; i <= ile; i++){
        SecondDist[i] = dist[i];
    }
    //cout<<FirstCandidate<<" "<<SecondCandidate;/*
    for(int i = 1; i <= ile; i++){
        cout << max(FirstDist[i], SecondDist[i]) - 1 << "\n";
    }
    return 0;
}


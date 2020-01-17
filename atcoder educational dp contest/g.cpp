#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#define INF 1000000005

using namespace std;


int n, m;//n vertices m edges

vector<int> tab[1000000];
int sc[1000000];
int x, y;
int score = 0;

int check(int vertex){
    
    if(sc[vertex] != 0){
        return sc[vertex];
    }
    //cout << vertex << "\n";
    
    int score = 1;
    for(int i = 0; i < tab[vertex].size(); i++){
        if(sc[vertex] != 0){
            score = max(score, sc[vertex]);
        }
        else{
            score = max(score, check(tab[vertex][i]) + 1);
        }
    }
    sc[vertex] = score;
    return score;
}


int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        tab[x].push_back(y);
    }
    
    
    for(int i = 1; i <= n; i++){
        score = max(score, check(i));
    }
    
    cout << score - 1;
}


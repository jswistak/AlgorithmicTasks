#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> krawedz[500010];
vector<int> odwrocona[500010];


int liczb, nier, ile, a, b;
int cyklnr = 1;

int odw[500010];
int spoj[500010];

vector <int> q;

//Zwykly DFS
void dfs(int wierz){
    odw[wierz] = 1;
    for(int i = 0; i < krawedz[wierz].size(); i++){
    
        if(odw[krawedz[wierz][i]] == 0){
            dfs(krawedz[wierz][i]);
        }
    }
   // cout<<"zakonczono "<< wierz<<endl;
    q.push_back(wierz);
       
}
//SSS
void dfs1(int wierz, int czas){
    
    spoj[wierz] = czas;
    
    for(int i = 0; i < odwrocona[wierz].size(); i++){
    
        if(spoj[odwrocona[wierz][i]] == 0){
            dfs1(odwrocona[wierz][i], czas);
        }
    }
    
}

int zapytan;

int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> ile >> nier;
    
    for(int i = 0; i < nier; i++){
        
        cin >> a >> b;
        if(a != b){
            krawedz[b].push_back(a);
            odwrocona[a].push_back(b);
        }
    }
    
    for(int i = 1; i <= ile; i++){
        if(odw[i] == 0){
            dfs(i);
        }
    }
    for(int i = 1; i <= q.size(); i++){
        if(spoj[q[q.size() - i]] == 0){
            dfs1(q[q.size() - i], i);
        }
    }
    /*
    for(int i = 1; i <= ile; i++){
        cout << i << " " << spoj[i] << "\n";
    }
    */
    //Odp na zapytania
    cin >> zapytan;
    for(int i = 0; i < zapytan; i++){
        cin >> a >> b;
        if(spoj[a] == spoj[b]){
            cout << "Tak\n";
        }
        else{
            cout << "Nie\n";
        }
    }
    return 0;
}


#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>



#define INF 100000000
//TODO sprawdzic n = 1

using namespace std;

int n, m, testow, potdwa = 1;
//long long tree[1000000];
long long a, b, c;
vector <long long> pom;
int x;
//vector< vector <int> > tab;
priority_queue<long long> q;
long long wynik;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> x;
            pom.push_back(x);
        }
        sort(pom.begin(), pom.end());
        
        //cout<< "\n\n";
        //for(auto a : pom)cout << a << " ";
        
        for(int j = 0; j < pom.size(); j++){
            pom[j] += 1 + 2 * j;
            q.push(-pom[j]);
        }
        pom.clear();
        wynik += q.top();
        q.pop();
    }
    
    cout << -wynik;
    
    
}

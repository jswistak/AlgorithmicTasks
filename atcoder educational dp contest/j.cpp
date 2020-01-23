#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <iomanip>


using namespace std;

int n, x;
double score;
int tab[5];
double ex[305][305][305];
double p[305][305][305];
//ex[a][b][c] = expected number of operations to get to state a, b, c
//p[a][b][c] = propability of getting to this state
int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    //dp[a][b][c] = expected value of operations to get to state a, b, c
    for(int i = 0; i < n; i++){
        cin >> x;
        tab[x]++;
    }
    //p[tab[1]][tab[2]][tab[3]]
    
    p[tab[1]][tab[2]][tab[3]] = 1;
    for(int c = n; c >= 0; c--){
        for(int b = n; b >= 0; b--){
            for(int a = n; a >= 0; a--){
                if(a == 0 & b == 0 & c == 0){
                    continue;
                }
                if(a + b + c > n){
                    continue;
                }
                
                double pWaste = (double)  (n - (a + b + c)) / n;
                double exWaste = pWaste / (1 - pWaste) + 1;
                
                ex[a][b][c] += exWaste * p[a][b][c];
                
                if(a != 0){
                    double pGo = (double) a / (a + b + c);
                    p[a - 1][b][c] += p[a][b][c] * pGo;
                    ex[a - 1][b][c] += ex[a][b][c] * pGo;
                }
                
                
                if(b != 0){
                    double pGo = (double) b / (a + b + c);
                    p[a + 1][b - 1][c] += p[a][b][c] * pGo;
                    ex[a + 1][b - 1][c] += ex[a][b][c] * pGo;
                }
                
                if(c != 0){
                    double pGo = (double) c / (a + b + c);
                    p[a][b + 1][c - 1] += p[a][b][c] * pGo;
                    ex[a][b + 1][c - 1] += ex[a][b][c] * pGo;
                }
                
            }
        }
    }
    
    
    
    cout << setprecision(10) << ex[0][0][0];
}


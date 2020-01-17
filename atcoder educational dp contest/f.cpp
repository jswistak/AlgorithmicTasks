#include <iostream>
#include <algorithm>
#include <utility>
#include <string>

#define INF 1000000005

using namespace std;


int dp[4000][4000];
int tab[4000][4000];

string c1, c2;
string score = "";

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> c1 >> c2;
    
    for(int i = 0; i < c1.size(); i++){
        for(int j = 0; j < c2.size(); j++){
            if(c1[i] == c2[j]){
                tab[i][j]++;
            }
        }
    }
    
    for(int i = 1; i <= c1.size(); i++){
        for(int j = 1; j <= c2.size(); j++){
            dp[i][j] = max(max(dp[i][j - 1], dp[i - 1][j - 1] + tab[i - 1][j - 1]), dp[i - 1][j]);
            
            
        }
    }
    //cout << dp[c1.size()][c2.size()];
    
    
    //recover string
    int point1 = c1.size();
    int point2 = c2.size();
    
    while(score.size() < dp[c1.size()][c2.size()]){
        if(dp[point1][point2] == dp[point1][point2 - 1]){//nic nie bralem wiec continue
            point2--;
            continue;
            
        }
        else if(dp[point1][point2] == dp[point1 - 1][point2 - 1] + tab[point1 - 1][point2 - 1]){
            point2--;
            point1--;
            score += c1[point1];
        }
        else{
            point1--;
        }
    }
    //score.reverse()
    reverse(score.begin(), score.end());
    cout << score;
    
    
}


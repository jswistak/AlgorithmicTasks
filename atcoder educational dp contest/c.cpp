#include <iostream>
#include <algorithm>

#define INF 1000000005


using namespace std;

int n, k;
int tab[1000000][3];
int dp[1000000][3];
int main(){
    
    cin >> n;
    
    
	for(int i = 0; i < n; i++){
		cin >> tab[i][0] >> tab[i][1] >> tab[i][2];
	}
    
    
	for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            dp[i][j] = max(dp[i - 1][(j + 1) % 3] + tab[i][(j + 1) % 3], dp[i - 1][(j + 2) % 3] + tab[i][(j + 2) % 3]);
        }
        
    }
    /*
    for(int i = 0; i < n; i++){
        cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << "\n";
    }*/
	cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));

}


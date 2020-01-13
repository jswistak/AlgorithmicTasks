#include <iostream>
#define INF 1000000005
using namespace std;

int n, k;
int tab[1000000];
int dp[1000000];
int main(){
    
    cin >> n >> k;
    
    for(int i = 1; i < n + 5; i++){
        dp[i] = INF;
    }
	for(int i = 0; i < n; i++){
		cin >> tab[i];
	}
    
    //cout<<dp[10];
	for(int i = 0; i < n; i++){
        for(int j = 1; j <= k; j++){
            dp[i + j] = min(dp[i + j], dp[i] + abs(tab[i] - tab[i + j]));
        }
        
    }
	cout << dp[n - 1];

}


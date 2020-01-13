#include <iostream>
#define INF 1e9 + 5
using namespace std;

int n;
int tab[1000000];
int dp[1000000];
int main(){
	cin >> n;
    
    for(int i = 1; i < n + 5; i++){
        dp[i] = INF;
    }
	for(int i = 0; i < n; i++){
		cin >> tab[i];
	}
    
    //cout<<dp[10];
	for(int i = 0; i < n; i++){
		dp[i + 1] = min(dp[i + 1], dp[i] + abs(tab[i] - tab[i + 1]));
		dp[i + 2] = min(dp[i + 2], dp[i] + abs(tab[i] - tab[i + 2]));
	}
	cout << dp[n - 1];

}


#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <iomanip>
#define INF 1000000005

using namespace std;

const long long MOD = 1000000007;

int n;
double dp[4010];
double coin;
double score;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    dp[0] = 1;
    //dp[i] = propability that there are i heads
    for(int i = 0; i < n; i++){
        cin >> coin;
        for(int j = i; j >= 0; j--){
            dp[j + 1] += coin * dp[j];
            dp[j] = (1 - coin) * dp[j];
            
        }
    }
    
    double answer = 0;
    
    for(int heads = 0; heads <= n; heads++){
        int tails = n - heads;
        if(heads > tails){
            answer += dp[heads];
        }
    }
    
    cout << setprecision(10) << answer;
    
    
}


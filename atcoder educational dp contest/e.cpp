#include <iostream>
#include <algorithm>
#include <utility>

#define INF 1000000005


using namespace std;

long long n, size;
pair <long long, long long> tab[100000];
long long dp[1000000];
long long minimum = INF;
long long score = 0;

int main(){
    
    for(int i = 1 ; i < 1000000; i++){
        dp[i] = INF;
    }
    cin >> n >> size;
    
    
    for(int i = 0; i < n; i++){
        cin >> tab[i].first >> tab[i].second;
        // first - weight
        // second - value
    }
    
    long long maxValue = 0;
    
    for(int element = 0; element < n; element++){
        for(int i = maxValue; i >= 0; i--){
            
            dp[i + tab[element].second] = min(dp[i + tab[element].second], dp[i] + tab[element].first);
            maxValue = max(maxValue, i + tab[element].second);
            
        }
        
    }
   
    for(int i = maxValue; i >= 0; i--){
        if(dp[i] <= size){
            cout << i;
            return 0 ;
        }
    }
    
}

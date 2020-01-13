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
    
    cin >> n >> size;
    
    
	for(int i = 0; i < n; i++){
        cin >> tab[i].first >> tab[i].second;
        // first - weight
        // second - value
        minimum = min(minimum, tab[i].first);//do kiedy mam sprawdzac od dp[pojemnosc] do do[pojemnosc - minimum]
	}
    
    
    for(int element = 0; element < n; element++){
        for(int i = size; i >= 0; i--){
            dp[i + tab[element].first] = max(dp[i + tab[element].first], dp[i] + tab[element].second);
            
        }
        
    }
    
    
    for(int i = 0; i < minimum; i++){
        score = max(score, dp[size - i]);
    }
    cout << score;
}


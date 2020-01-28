#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <iomanip>


using namespace std;

int n, k, x;
vector <int> vec;
int tab[1000];
int dp[1000000];
int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        cin >> x;
        vec.push_back(x);
    }
    
    for(int stones = 0; stones <= k; stones++){
        for(auto x : vec){
            if(stones >= x && !dp[stones - x])
                dp[stones] = 1;
            
        }
    }
    cout << (dp[k] ? "First" : "Second");
}


#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <iomanip>


const int mod = 1e9 + 7;

using namespace std;

int n, k, x;
int dp[1000000];


int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, k;
    cin >> n >> k;
    // dp[i] - the number of ways such that we used i candies so far
    dp[0] = 1;
    for(int child = 0; child < n; ++child) {
        int upto;
        cin >> upto;
        vector<int> fake(k + 1);
        for(int used = k; used >= 0; --used) {
            int tmp = dp[used];
            int L = used + 1;
            int R = used + min(upto, k - used);
            if(L <= R) {
                
                fake[L] += tmp;
                if(fake[L] >= mod){
                    fake[L] -= mod;
                }
                if(R + 1 <= k) {
                    fake[R + 1] -= tmp;
                    if(fake[R + 1] < 0){
                        fake[R + 1] += mod;
                    }
                    
                }
            }
        }
        int prefix_sum = 0;
        for(int i = 0; i <= k; ++i) {
            
            prefix_sum += fake[i];
            if(prefix_sum >= mod){
                prefix_sum -= mod;
            }
            
            dp[i] += prefix_sum;
            if(dp[i] >= mod){
                dp[i] -= mod;
            }
        }
    }
    cout << dp[k];
    
}


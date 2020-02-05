#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

using ll = long long;
const ll INF = 1e18L + 5;
const int mod = 1e9 + 7;

int n;
string k;

void add(int& a, int b){
    a += b;
    if(a >= mod){
        a -= mod;
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> k;
    int D;
    cin >> D;
    vector<vector<int>> dp(D, vector<int>(2));
    //dp[sum][smaller_already] number of ways to chose digits so far such that the sum of digits modulo D is sum and smaller already says whether we already chosen some digit smaller than in K
    int len = k.size();
    dp[0][0] = 1;
    for(int where = 0; where < len; where++){
        vector<vector<int>> newDp(D, vector<int>(2));
        for(int sum = 0; sum < D; sum++){
            for(bool sm_already : {false, true}){
                for(int digit = 0; digit < 10; digit++){
                    if(digit > k[where] - '0' && !sm_already){
                        break;
                    }
                    add(newDp[(sum + digit) % D][sm_already || (digit < k[where] - '0')], dp[sum][sm_already]);
                }
            }
        }
        dp = newDp;
    }
    int answer = dp[0][false] + dp[0][true] - 1;
    answer %= mod;
    if(answer == -1){
        answer = mod - 1;
    }
    cout << answer;
}


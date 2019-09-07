#include <iostream>
#include <algorithm>
#include <numeric>
//#include <bits/stdc++.h>
using namespace std;

int GCD(int a,int b){
    int temp;
    while(b!=0){
        temp=a%b;
        a=b;
        b=temp;
    }
    return a;
    
}

/*
 int gcd(ll x, ll y){
    if(y == 0)return x;
    return gcd(y, x%y);
}
 */

long long n, m;
int main(){
    cin >> n >> m;
    int c=0;
    //cout << GCD(n,m);
    unsigned long long score = n*(n-1)*m*(m-1)/4;
    for(int i = 1; i <= 400; i++){
        for(int j = 1; j <= 400; j++){
            if(GCD(i, j) != 1)
                continue;
            for(int timesf = 1; timesf <= 400; timesf++){
                if(timesf * i + j >= n || timesf * j + i >= m)
                    break;
                for(int timesb = 1; timesb <= 400; timesb++){
                    if(timesf * i + j * timesb >= n || timesf * j + i * timesb >= m){
                        break;
                    }
                    c++;
                    //cout << timesb * j + timesf * i << " " << timesf * j + i + timesb << "\n";
                    score += (n - (i * timesf + j * timesb)) * (m - (j * timesf + i * timesb));
                    //cout<< score << " ";
                }
            }
        }
    }
    //cout<<c<<endl;
    cout << score << "\n" << flush;
    return 0;
}


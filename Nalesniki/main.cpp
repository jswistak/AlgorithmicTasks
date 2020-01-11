#include <iostream>
#include <algorithm>

using namespace std;

int n,m;

int a[2004];
int b[2004];
int prefa[2004];
int prefb[2004];

int dp[2004][2020];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //Wczytaj
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i];
    }
    
    //Oblicz prefiksy
    
    
    for(int i = 1; i <= n + 1; i++){
        prefa[i] = prefa[i - 1] + a[i - 1];
    }
    for(int i = 1; i <= m + 1; i++){
        prefb[i] = prefb[i - 1] + b[i - 1];
    }
    
    
    // Dziala
    /*
    cout<<"a";
    for(int i=0;i<=n +1;i++){
        cout<<a[i]<< " ";
    }
    cout<<endl<<endl;
    cout<<"b";
    for(int i=0;i<=m +1;i++){
        cout<<b[i]<< " ";
    }
    cout<<endl<<endl;
    cout<<"prefa";
    for(int i=0;i<=n +1;i++){
        cout<<prefa[i]<< " ";
    }
    cout<<endl<<endl;
    cout<<"prefa";
    for(int i=0;i<=m +1;i++){
        cout<<prefb[i]<< " ";
    }
    */
    //Gen pierwsz wiersz
    
    //A
    //dp[1][0] = a[1];
    //dp[2][0] = a[2];
    /*
     for(int i = 1; i <= n; i++){
        if(i > 1){
            dp[i][0] = dp[i -2][0] + a[i];
        }
        else{
            dp[i][0] = a[i];
        }
        //cout << dp[i][0] << " ";
        
    }*/
  //  cout << endl;
    //B
    for(int i = 1; i <= m; i++){
           if(i > 1){
               dp[0][i] = dp[0][i -2] + b[i];
           }
           else{
               dp[0][i] = b[i];
           }
           //cout << dp[0][i] << " ";
           
    }
    //Dziala
    
    
   // cout<<endl<<endl;
    //Dp
    
    for(int i = 1; i <= n; i++){
        dp[i % 2][0] += a[i];
        for(int j = 1; j <= m; j++){
            /*
            if(j == 0){
                dp[i % 2][j] = a[i];
            }*/
            
            dp[i % 2][j] = prefa[i + 1] + prefb[j] - dp[i % 2][j - 1] + b[j];
            dp[i % 2][j] = max(prefa[i] + prefb[j + 1] - dp[(i - 1) % 2][j] + a[i], dp[i % 2][j]);
            /*
            if(i==2 && j==1){
                cout << prefa[i + 1] + prefb[j] - dp[i][j - 1] << b[j] << endl;//chyba 12
                cout << prefa[i] + prefb[j + 1] - dp[i - 1][j] << a[i] << endl;
                
            }*/
            
        }
    }
    //cout<<dp[n][m];
    /*
    cout << endl << endl;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            cout << dp[i][j] << " ";
        } cout << endl;
    }*/
    cout << dp[n % 2][m];
}


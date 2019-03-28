#include <bits/stdc++.h>

using namespace std;

int ile,a,b,wynik=300000;
vector < int > tab[300010];
int dp[300100];
//Zeruje
void zeruj(){
    for(int i=1;i<=ile;i++){
        dp[i]=-ile;
    }
}

int rekur(int ekip, int index, int z){
    int x=0;
    for(int i=0;i<tab[index].size();i++){
        //TODO xd
        //cout<<"AA";
        if(z!=tab[index][i]){
            if(dp[tab[index][i]]==-ile){
                //      cout<<"B";
                rekur(ekip, tab[index][i], index);
            }
            x+=dp[tab[index][i]]+1;
        }
        //dp[index]=x;
        
    }
    dp[index]=x;
    dp[index]-=ekip;
    //TODO
    //cout<<"a"<<index<<" "<<dp[index]<<endl;
    dp[index]=max(dp[index],0);
    //cout<<tab[index].size()<<endl;
    
    
    
    return dp[index];
}

int upperbound(){
    int wynik=ile-1;
    int p=1,k=ile-1,sr=(k+1)/2;
    while(p<=k){
        sr=(p+k)/2;
        zeruj();
        int x=rekur(sr,1,0);
        if(x>0){
            //cout<<"Nie da sie dla "<<sr<<"wartosc"<<x<<endl;
            p=sr+1;
        }
        else {
            wynik=sr;
            k=sr-1;
        }
    }
    
    return wynik;
}

int main(){
    cin>>ile;
    wynik=ile;
    for(int i=1;i<ile;i++){
        cin>>a>>b;
        tab[a].push_back(b);
        tab[b].push_back(a);
    }
    /*for(int i=0;i<ile;i++){
     if(tab[i].size()==1){
     dp[i]=0;
     }
     else{
     
     }
     }*/
    /*for(int i=1;i<ile-1;i++){
     zeruj();
     cout<<rekur(i,1,0)<<" ";
     
     }*/
    //zeruj();
    //cout<<rekur(1,1,0)<<endl<<endl;
    cout<<upperbound();
    //cout<<endl;
    //cout<<rekur(3,1,0);
    //cout<<endl;
    
    
    return 0;
}

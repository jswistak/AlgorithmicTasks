#include <iostream>
#include <algorithm>
#include <cstdio>


using namespace std;

int poziomo,pionowo;
int tab[550][550];
int pref[550][550];

int wynik=0;
int w[600];

void spr(int p,int k){
	int wyn=0;int temp=0;
    w[poziomo]=pref[k][poziomo]-pref[p-1][poziomo];
	for(int i=poziomo;i>0;i--){
		w[i]=max(w[i+1]+pref[k][i]-pref[p-1][i],pref[k][i]-pref[p-1][i]);
		wynik=max(w[i],wynik);
	}
}

int main(){
	scanf("%d%d",&pionowo,&poziomo);
	for(int i=1;i<=pionowo;i++){
		for(int j=1;j<=poziomo;j++){
			scanf("%d",&tab[i][j]);
		}
	}
	for(int i=1;i<=pionowo;i++){
		for(int j=1;j<=poziomo;j++){
			pref[i][j]=tab[i][j]+pref[i-1][j];
		}
	}
	/*
	for(int i=1;i<pionowo;i++){
		for(int j=1;j<=poziomo;j++){
			cout<<pref[i][j];
		}
	}
	*/
	for(int i=1;i<=pionowo;i++){
        //cout<<i<<"<="<<poziomo<<"\n";
		for(int j=i;j<=pionowo;j++){
            //cout<<i<<"<="<<poziomo<<" "<<j<<"\n";
            
			spr(i,j);
		}
	}
	cout<<wynik;



	return 0;
}

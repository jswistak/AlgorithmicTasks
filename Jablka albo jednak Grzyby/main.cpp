#include <iostream>
#include <vector>

using namespace std;

int getint(){
    int value=0;
    char ch;
    do{
        ch=getchar_unlocked();
    }while(ch<'0' || '9'<ch);
    do{
        value=value*10+ch-'0';
        ch=getchar_unlocked();
    }while(ch>='0' && '9'>=ch);
    return value;
}

int wyn[1000100];
int ile,wynik,a,b;
int tab[1000100];
vector <int> krawdz[1000000];
void BFS(int v,int curwyn){
	wyn[v]=curwyn;
	for(int i=0;i<krawdz[v].size();i++){
		if(wyn[krawdz[v][i]]==0){
			BFS(krawdz[v][i],curwyn+1);
		}
	}
}
int wierzcholek;


int main(){
	ile=getint();

    for(int i=0;i<ile-1;i++){
        a=getint();
        b=getint();
        krawdz[a].push_back(b);
        krawdz[b].push_back(a);
    }

	BFS(1,0);

	for(int i=0;i<=ile;i++){
        if(wynik<wyn[i]){
            wynik=wyn[i];
            wierzcholek=i;
            wyn[i]=0;
        }
	}
    BFS(wierzcholek,0);
    for(int i=0;i<=ile;i++){
        wynik=max(wynik,wyn[i]);
    }
	cout<<wynik;
	
	
}


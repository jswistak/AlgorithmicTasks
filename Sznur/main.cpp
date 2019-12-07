#include <iostream>
#include <string>
#include <algorithm>

#define INF 1000000
using namespace std;

string ciag;
int dlugosc, maks, zlicz;
int wynik = 0;
int tab[1000020];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    
    cin >> ciag;
    cin>> dlugosc;
    int ile = ciag.size();
    
    
    for(int i = 0; i < ile; i++){
        if(ciag[i] == 'M'){
            zlicz++;
        }
        else{
            maks = max(zlicz, maks);
            zlicz = 0;
        }
    }
    maks = max(zlicz, maks);
    if(maks == dlugosc){
        cout << 0;
        return 0;
    }
    zlicz = 0;
    if(maks > dlugosc){
        //breakujemy az mozemy
        for(int i = 0; i < ile; i++){
            if(ciag[i] == 'M'){
                zlicz++;
            }
            if(ciag[i] == 'L'){
                zlicz = 0;
            }
            if(zlicz > dlugosc){
                wynik++;
                ciag[i] = 'L';
                zlicz = 0;
            }
        }
        cout << wynik;
        return 0;
    }
    else{
        zlicz = 0;
        
        //przedluzamy dlugosc sznura
        for(int i = 0; i < dlugosc; i++){
            if(ciag[i] == 'L'){
                zlicz++;
            }
        }
        tab[dlugosc - 1] = zlicz;
        for(int i = dlugosc; i < ile; i++){
            tab[i] = tab[i - 1];
            if(ciag[i - dlugosc ] == 'L'){
                tab[i]--;
            }
            if(ciag[i] == 'L'){
                tab[i]++;
            }
        }
        /*
        for(int i = 0; i < ile; i++){
            cout << tab[i] << " ";
        }*/
        wynik = INF;
        int lokal = tab[dlugosc - 1];
        if(ciag[dlugosc] == 'M'){
            lokal++;
        }
        wynik = min(lokal, wynik);
        //cout<<wynik;
        for(int i = dlugosc; i < ile; i++){
            lokal = tab[i];
            if(ciag[i - dlugosc] == 'M'){
                lokal++;
            }
            else if(ciag[i + 1] == 'M'){
                lokal++;
            }
            //cout<<i<<" "<<lokal<<" "<<tab[i]<<endl;
           wynik = min(lokal, wynik);
        }
        
        cout << wynik;
    }
    
    return 0;
}

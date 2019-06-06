#include <iostream>

using namespace std;
const int INF = 1000000;
int n, m;
char zn;
int tab[200][200];
int wynik[200][200];
int odl;
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> zn;
            tab[i][j] = zn - '0';
        }
    }
    for(int i = 0; i < 200; i++){
        for( int j = 0; j < 200; j++){
            if(tab[i][j] == 0){
                wynik[i][j] = INF;
            }
        }
    }
    
    //DONE
    for(int i = 0; i < n; i++){
        odl = wynik[i][0];
        for(int j = 0; j < m; j++){
            odl = min(odl + 1, wynik[i][j]);
            wynik[i][j] = odl;
            //cout << tab[i][j] << " ";
        }//cout << endl;
    }
    
    
    for(int i = 0; i < n; i++){
        odl = wynik[i][m - 1];
        for(int j = m - 1; j >= 0; j--){
            odl = min(odl + 1, wynik[i][j]);
            wynik[i][j] = odl;
        }//cout << endl;
    }
    
    //pionowo
    for(int i = 0; i < m; i++){
        odl = wynik[0][i];
        for(int j = 0; j < n; j++){
            odl=min(odl + 1, wynik[j][i]);
            wynik[j][i] = odl;
            //cout << tab[i][j] << " ";
        }//cout << endl;
    }
    
    
    for(int i = 0; i < m; i++){
        odl = wynik[n - 1][i];
        for(int j = n - 1; j >= 0; j--){
            odl=min(odl + 1, wynik[j][i]);
            wynik[j][i] = odl;
        }//cout << endl;
    }
    
    //wypisz wynik
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << wynik[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


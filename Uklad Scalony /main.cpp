#include <iostream>
#include <algorithm>

using namespace std;
int tab[1010][1010];
int wysokosc, dlugosc, k;
int zmieniono = 0;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> wysokosc >> dlugosc >> k;
    //cout << wysokosc << " " << dlugosc << " " << k << endl;
    
    int nowek = k;
    if(dlugosc % 2 == 0 && wysokosc != 2){
        
        int pom = dlugosc;
        dlugosc = wysokosc;
        wysokosc = pom;
        zmieniono = 1;
    }
    //Decyduj czy mozna
    if(k <= wysokosc * dlugosc - 1){
        //cout << '1';
        if(wysokosc == 1 && dlugosc == 1 && k == 0){
            //cout << "TAK\n";
            return 0;
        }
        if(k >= wysokosc + dlugosc - 2 && (dlugosc % 2 == 1 || wysokosc % 2 == 1)){
           // cout << "TAK\n";
        }
        else if(k >= wysokosc + dlugosc - 1){
           // cout << "TAK\n";
        }
        else{
            cout << "NIE";
            return 0;
        }
        
    }
    else{
        cout << "NIE";
        return 0;
    }
    
    
    //generuj siatke o najdluzszej sciezce o dl k
    
    
    
    
    //Zmieniamy parzystosc
    //cout << "jej";
    
    if(dlugosc == 2 || wysokosc == 2){
        //TODO: napisac gdy jeden jest rowny 2
        //cout << zmieniono << endl << endl;
        for(int i = 1; i <= dlugosc; i++){
            tab[1][i] = 2;
        }
        tab[1][dlugosc] = 3;
        tab[2][dlugosc] = 3;
        
        //debug
        for(int i = 1; i < dlugosc; i++){
            tab[2][i] = 1;
        }
        int sciezka = wysokosc + dlugosc - 1;
        
        for(int i = 2; i < dlugosc; i++){
            if(sciezka < k){
                sciezka++;
                tab[2][i] = 4;
            }
        }
        
    }
    else if(dlugosc % 2 == 1){
        
        k -= wysokosc - 1;
        //TODO:ZMIENIALEM Obliczanie k
        int dokad = k / 2;
        
        dokad++;//bo to jest ile chce wykonac skokow
        if(dokad > dlugosc){
            dokad = dlugosc;
        }
        //cout<<dokad<<" ";
        for(int i = 1; i <= wysokosc; i++){
            for(int j = 1; j < dokad; j++){
                if(tab[i][j] == 0)
                    tab[i][j] = 2;
            }
        }
        for(int i = 1; i <= wysokosc; i++){
            tab[i][dokad] = 3;
            
        }
        
        
        for(int i = wysokosc; i > 0; i--){
            for(int j = dlugosc; j > 0; j--){
                if(tab[i][j] == 0){
                    tab[i][j] = 4;
                }
            }
        }
            
        //drabinka
        //powinno dzialac juz
        k -= (dokad - 1) * 2;
        int kierunek = 1;
        int x = 1;
        int y = wysokosc;
        //cout << k;
        /*
        cout << endl << endl << endl;
        for(int i = 1; i <= wysokosc; i++){
            for(int j = 1; j <= dlugosc; j++){
                cout << tab[i][j] << " ";
            }cout << endl;
        }cout << endl << endl << endl;*/
        //cout << " " << k << " ";
        //cout << tab[2][1];
        if(wysokosc != 3){
            
            while(k > 0){
                //cout << x << " " << y;
                k--;
                if(kierunek == 1){
                    y--;
                    tab[y][x] = 3;
                    if(y == 2){
                        kierunek = 2;
                    }
                }
                else if(kierunek == 2 && y == 2){
                    x++;
                    tab[y][x] = 4;
                    kierunek = 3;
                }
                else if(kierunek == 3){
                    y++;
                    tab[y][x] = 1;
                    if(y + 1 == wysokosc){
                        kierunek = 2;
                    }
                }
                else if(kierunek == 2){
                    x++;
                    tab[y][x] = 4;
                    kierunek = 1;
                }
                
                //idz do gory poki mozesz potem jak mozesz to srodek i bardziej do wewnatrz
            }
        }
        else if(k > 0){
            int ind = 1;
            while(k > 0){
                k--;
                tab[2][ind] = 4;
                ind++;
            }
            tab[2][1] = 3;
        }
        
       
    }
    else {
         k -= wysokosc - 1;
         //cout<<k;
         //cout<<" "<<k<<" ";
         //TODO:ZMIENIALEM Obliczanie k
         int dokad = k / 2;
        /*if(k % 2 == 1){
            dokad++;
        }*/
         dokad++;//bo to jest ile chce wykonac skokow
        if(dokad > dlugosc){
            dokad = dlugosc;
        }
         //cout<<dokad<<" ";
         for(int i = 1; i <= wysokosc; i++){
             for(int j = 1; j < dokad; j++){
                 if(tab[i][j] == 0)
                     tab[i][j] = 2;
             }
         }
         for(int i = 1; i <= wysokosc; i++){
             tab[i][dokad] = 3;
             //cout<<i<<" "<<dokad<<endl;
         }
         //cout<<dokad;
         for(int i = wysokosc; i > 0; i--){
             for(int j = dlugosc; j > 0; j--){
                 if(tab[i][j] == 0){
                     tab[i][j] = 4;
                 }
             }
         }
             
         //drabinka
         //powinno dzialac juZ
         k -= (dokad - 1) * 2;
         int kierunek = 1;
         int x = 1;
         int y = wysokosc;
         //cout<<k<<" ";
        if(wysokosc == 2 && k == 1){
            for(int i = 2; i <= dlugosc; i++){
                if(tab[0][i] == 3){
                    for(int j = 1; j<= wysokosc;j++){
                        tab[j][i - 1] = 3;
                        tab[j][i] = 4;
                    }
                    break;
                }
            }
            tab[2][dlugosc] = 1;
        }
         if(wysokosc != 3){
             while(k > 0){
                 k--;
                 if(kierunek == 1){
                     y--;
                     tab[y][x] = 3;
                     if(y == 2){
                         kierunek = 2;
                     }
                 }
                 else if(kierunek == 2 && y == 2){
                     x++;
                     tab[y][x] = 4;
                     kierunek = 3;
                 }
                 else if(kierunek == 3){
                     y++;
                     tab[y][x] = 1;
                     if(y + 1 == wysokosc){
                         kierunek = 2;
                     }
                 }
                 else if(kierunek == 2){
                     x++;
                     tab[y][x] = 4;
                     kierunek = 1;
                 }
                 
                 
                 //idz do gory poki mozesz potem jak mozesz to srodek i bardziej do wewnatrz
             }
         }
         
         else if(k > 0){
             //for(int i = 1; i < dokad;i++)
             int ind = 1;
             while(k > 0){
                 k--;
                 tab[2][ind] = 4;
                 ind++;
             }
             tab[2][1] = 3;
         }
         
        
    }
    //wys parzysta
    //for(int i = 1; i <= wysokosc)
    
    // wys parzysta
    // szer parzysta
    //obie nieparzyste
    
    //cout<<k<<endl;
    
    
    /*
    cout << endl << endl << endl;
    for(int i = 1; i <= wysokosc; i++){
        for(int j = 1; j <= dlugosc; j++){
            cout << tab[i][j] << " ";
        }cout << endl;
    }cout << endl << endl << endl;
    */
    //cout<<endl<<endl;
    if(zmieniono == 1){//odwrocono
        for(int i = 1; i <= wysokosc; i++){
            for(int j = 1; j <= dlugosc; j++){
                //wypisz tab j i
                if(tab[i][j] == 1 && i - 1 > 0){
                    cout << j << " " << i << " " << j << " " << i - 1 << "\n";
                }
                else if(tab[i][j] == 2 && j + 1 <= dlugosc){
                    cout << j << " " << i << " " << j + 1 << " " << i << "\n";
                }
                else if(tab[i][j] == 3 && i + 1 <= wysokosc){
                    cout << j << " " << i << " " << j << " " << i + 1 << "\n";
                }
                else if(tab[i][j] == 4 && j - 1 > 0){
                    cout << j << " " << i << " " << j - 1 << " " << i << "\n";
                }
                else{
                   // cout<<"Alert"<<i <<" "<<j<<" "<<tab[i][j]<<endl;
                }
                
            }
        }
    }
    else{
        for(int i = 1; i <= wysokosc; i++){
            for(int j = 1; j <= dlugosc; j++){
                //wypisz tab j i
                if(tab[i][j] == 1 && i - 1 > 0){
                    cout << i << " " << j << " " << i - 1 << " " << j << "\n";
                }
                else if(tab[i][j] == 2 && j + 1 <= dlugosc){
                    cout << i << " " << j << " " << i << " " << j + 1 << "\n";
                }
                else if(tab[i][j] == 3 && i + 1 <= wysokosc){
                    cout << i << " " << j << " " << i + 1 << " " << j << "\n";
                }
                else if(tab[i][j] == 4 && j - 1 > 0){
                    cout << i << " " << j << " " << i << " " << j - 1 << "\n";
                }
                else{
                    //cout<<"Alert"<<i <<" "<<j<<" "<<tab[i][j]<<endl;
                }
                
            }
        }
    }
    
    //pamietac aby wypisywac zmienne (y,x)
    //zawsze jeden element bd wskazywac poza mape ! niewypisujemy go wtedy !!!
    return 0;
}

#include <iostream>
#include <vector>


using namespace std;


int lokalCzas;
int globalCzas;//moze bedziemy mogli go zastapic zmienna i
int czasTab[1000000];

vector<int> drzewo[1000000];
int wartosciDrzewa[1000000];

char znak;
int ile;
int liczba;

int cofiniecia;

int main(){
    
    drzewo[0].push_back(0);
    cin >> ile;
    wartosciDrzewa[0] = -1;
    for(int i = 1; i <= ile; i++){
        cin >> znak;
        
        if(znak == '+'){
            cin >> liczba;
            drzewo[i].push_back(lokalCzas);
            wartosciDrzewa[i] = liczba;
            lokalCzas = i;
            
            cout << wartosciDrzewa[i] << endl;
            czasTab[i] = i;
            //operacja +
            
            //dodaj w globaltimie wierzcholek i polacz go z wierzcholkiem z current time
            
        }
        
        else if(znak == '-'){
            
            lokalCzas = drzewo[lokalCzas][0];
            if(lokalCzas < 0){
                lokalCzas = 0;
            }
            cout << wartosciDrzewa[lokalCzas] << endl;
            //operacja -
            czasTab[i] = lokalCzas;
            //idz wierzcholkiem w localtime o jeden
        }
        else if(znak == '*'){
            //TODO: Nie dziala jeszcze
            cin >> liczba;
            
            /*Debug
            cout<<endl;
            for(int i=0;i<10;i++){
                cout<<czasTab[i]<<" ";
            }cout<<endl;
            for(int i=0;i<10;i++){
                cout << wartosciDrzewa[czasTab[i]] << " ";
            }
            */
            
            
            lokalCzas = czasTab[i - liczba - 1] ;//+ cofiniecia;
            //cout<<"xd "<<i<<" xd "<<lokalCzas<<" xd"<<endl;
            cout << wartosciDrzewa[lokalCzas] << endl;
            czasTab[i] = lokalCzas;
            cofiniecia++;
            //operacja * (czas)
            
            //idz czasem o jednostke w tabli czas
            
        }
        
        
        
        
        
        
    }


	return 0;
}

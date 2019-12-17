#include <iostream>
#include <vector>
using namespace std;



int ile;
int tab[1000100];
vector<int> kolejka;
int wynik;

int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> ile;
    
    for(int i = 0; i < ile; i++){
        cin >> tab[i];
        
        if(i > 0 && tab[i] == tab[i - 1]){
            //usuwamy powtarzajace sie eleemnty
            i--;
            ile--;
        }
    }
    kolejka.push_back(0);
    for(int i = 0; i < ile; i++){
        while(kolejka.back() > tab[i]){
            kolejka.pop_back();
        }
        if(kolejka.back() != tab[i]){
            wynik++;
            kolejka.push_back(tab[i]);
        }
    }
    
    cout << wynik;
    return 0;
}
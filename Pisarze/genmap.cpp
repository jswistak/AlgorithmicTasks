#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <map>

//Mapujemy najczestsze wystapienia

using namespace std;
int testow;
string tekst;

int main(){
    int f = 0;
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    fstream mickiewicz;
    fstream prus;
    fstream sienkiewicz;
    mickiewicz.open("Mickiewicz.txt");
    prus.open("Prus.txt");
    sienkiewicz.open("Sienkiewicz.txt");
    ////Mickiewicz
    string mic;
    string sien;
    string pru;
    getline(mickiewicz, mic);
    getline(prus, pru);
    getline(sienkiewicz,sien);
    map < vector <char>, int  > mickie;
    vector<char> slowo;
    slowo.clear();
    
    for(int i = 0; i < mic.size(); i++){
        
        if(mic[i] >= '0' && mic[i] <= '9'){
            slowo.push_back(mic[i]);
        }
        else if(mic[i] >= 'A' && mic[i] <= 'Z'){
            slowo.push_back(mic[i]);
        }
        else if(mic[i] >= 'a' && mic[i] <= 'z'){
            slowo.push_back(mic[i]);
        }
        else{
            mickie.insert(make_pair(slowo,1));
            slowo.clear();
        }
    }
    //PRUS slownik
    map <  vector <char>, int  > pr;
    slowo.clear();
    
    for(int i = 0; i < pru.size(); i++){
    
        if(pru[i] >= '0' && pru[i] <= '9'){
            slowo.push_back(pru[i]);
        }
        else if(pru[i] >= 'A' && pru[i] <= 'Z'){
            slowo.push_back(pru[i]);
        }
        else if(pru[i] >= 'a' && pru[i] <= 'z'){
            slowo.push_back(pru[i]);
        }
        else{
            
            //na stos
            pr.insert(make_pair(slowo, 1));
            slowo.clear();
        }
    }
    
    //SIE
    map <  vector <char>, int  > sie;
    
    //vector<char> slowo;
    slowo.clear();
    for(int i = 0; i < sien.size(); i++){
        if(sien[i] >= '0' && sien[i] <= '9'){
            slowo.push_back(sien[i]);
        }
        else if(sien[i] >= 'A' && sien[i] <= 'Z'){
            slowo.push_back(sien[i]);
        }
        else if(sien[i] >= 'a' && sien[i] <= 'z'){
            slowo.push_back(sien[i]);
        }
        else{
            
            //na stos
            sie.insert(make_pair(slowo, 1));
            slowo.clear();
        }
    }
    
    
    ///mamy zmapowane slowa z wszystkich ksiazek
    //szukamy unikatow
    
    map <vector<char>,char> unikat;
    slowo.clear();
    
    for(int i = 0; i < sien.size(); i++){
        if(sien[i] >= '0' && sien[i] <= '9'){
            slowo.push_back(sien[i]);
        }
        else if(sien[i] >= 'A' && sien[i] <= 'Z'){
            slowo.push_back(sien[i]);
        }
        else if(sien[i] >= 'a' && sien[i] <= 'z'){
            slowo.push_back(sien[i]);
        }
        else{
            
            
            //sprawdz na pozostalych mapach jesli nie ma to dodaj jako unikat
            //sie
            //pr
            //mickie
            if(pr.find(slowo) == pr.end() && mickie.find(slowo) == mickie.end()){
                unikat.insert(make_pair(slowo, 'S'));
            }
            slowo.clear();
        }
    }
    
    slowo.clear();
    for(int i = 0; i < pru.size(); i++){
        if(pru[i] >= '0' && pru[i] <= '9'){
            slowo.push_back(pru[i]);
        }
        else if(pru[i] >= 'A' && pru[i] <= 'Z'){
            slowo.push_back(pru[i]);
        }
        else if(pru[i] >= 'a' && pru[i] <= 'z'){
            slowo.push_back(pru[i]);
        }
        else{
            
            //sprawdz na pozostalych mapach jesli nie ma to dodaj jako unikat
            //sie
            //pr
            //mickie
            if(sie.find(slowo) == sie.end() && mickie.find(slowo) == mickie.end()){
                unikat.insert(make_pair(slowo, 'P'));
            }
            
            slowo.clear();
        }
    }

    slowo.clear();
    for(int i = 0; i < mic.size(); i++){
        if(mic[i] >= '0' && mic[i] <= '9'){
            slowo.push_back(mic[i]);
        }
        else if(mic[i] >= 'A' && mic[i] <= 'Z'){
            slowo.push_back(mic[i]);
        }
        else if(mic[i] >= 'a' && mic[i] <= 'z'){
            slowo.push_back(mic[i]);
        }
        else{
            
            //sprawdz na pozostalych mapach jesli nie ma to dodaj jako unikat
            //sie
            //pr
            //mickie
            if(pr.find(slowo) == pr.end() && sie.find(slowo) == sie.end()){
                unikat.insert(make_pair(slowo,'M'));
            }
            slowo.clear();
        }
    }
    //mapa unikat zawiera uniatowe slowa dla tych lektor

    
    //zliczamy unikaty na mapie
    
    //Zliczamy unikaty SIE
    map < vector<char>, unsigned long long > zlicz;
    slowo.clear();
    for(int i = 0; i < sien.size(); i++){
        if(sien[i] >= '0' && sien[i] <= '9'){
            slowo.push_back(sien[i]);
        }
        else if(sien[i] >= 'A' && sien[i] <= 'Z'){
            slowo.push_back(sien[i]);
        }
        else if(sien[i] >= 'a' && sien[i] <= 'z'){
            slowo.push_back(sien[i]);
        }
        else{
            //sprawdz na pozostalych mapach jesli nie ma to dodaj jako unikat
            //sie
            //pr
            //mickie
            
            if(unikat.find(slowo) != unikat.end()){
                if(zlicz.find(slowo) == zlicz.end()){
                    zlicz.insert(make_pair(slowo, 1));
                }
                else{
                    unsigned long long x = zlicz.find(slowo)->second;
                    zlicz.erase(slowo);
                    zlicz.insert(make_pair(slowo, x + 1));
                    
                }
            }
            slowo.clear();
        }
    }
    //Zliczamy unikaty PRU

    //vector<char> slowo;
    slowo.clear();
    for(int i = 0; i < pru.size(); i++){
        if(pru[i] >= '0' && pru[i] <= '9'){
            slowo.push_back(pru[i]);
        }
        else if(pru[i] >= 'A' && pru[i] <= 'Z'){
            slowo.push_back(pru[i]);
        }
        else if(pru[i] >= 'a' && pru[i] <= 'z'){
                slowo.push_back(pru[i]);
        }
        else{
            //sprawdz na pozostalych mapach jesli nie ma to dodaj jako unikat
            //sie
            //pr
            //mickie
            
            if(unikat.find(slowo) != unikat.end()){
                if(zlicz.find(slowo) == zlicz.end()){
                    zlicz.insert(make_pair(slowo, 1));
                }
                else{
                    unsigned long long x = zlicz.find(slowo)->second;
                    zlicz.erase(slowo);
                    zlicz.insert(make_pair(slowo, x + 1));
                }
            }
            slowo.clear();
        }
    }
    //Zliczamy unikaty MIC
    slowo.clear();
    for(int i = 0; i < mic.size(); i++){
        if(mic[i] >= '0' && mic[i] <= '9'){
            slowo.push_back(mic[i]);
        }
        else if(mic[i] >= 'A' && mic[i] <= 'Z'){
            slowo.push_back(mic[i]);
        }
        else if(mic[i] >= 'a' && mic[i] <= 'z'){
                slowo.push_back(mic[i]);
        }
        else{
            //sprawdz na pozostalych mapach jesli nie ma to dodaj jako unikat
            //sie
            //pr
            //mickie
            
            if(unikat.find(slowo) != unikat.end()){
                if(zlicz.find(slowo) == zlicz.end()){
                    zlicz.insert(make_pair(slowo, 1));
                }
                else{
                    unsigned long long x = zlicz.find(slowo)->second;
                    zlicz.erase(slowo);
                    zlicz.insert(make_pair(slowo, x + 1));
                }
            }
            slowo.clear();
        }
    }
    
    //return 0;
    vector<char> asd;
    //szukamy najczestrzych unikatow
    
    vector<pair<int, pair<char, string > > >tab;
    int indeks = 0;
    map< vector<char>, char>::iterator itr;
    map< vector<char>, unsigned long long>::iterator it;
    for (itr = unikat.begin(); itr != unikat.end(); ++itr) {
        vector<char> tempor;
        tempor = itr->first;
        string zmien="";
        for(int i = 0; i < tempor.size(); i++){
            zmien += tempor[i];
        }
        it = zlicz.find(tempor);
        tab.push_back( make_pair(-it->second, make_pair(itr->second,zmien)));
        
    }
    
    sort(tab.begin(), tab.end());
    int zliczp = 0;
    int zliczm = 0;
    int zliczs = 0;
    
    //od tylu bo lepiej je ogladac w konsoli
    
    for(int i = 0; i < tab.size(); i++){
        if(tab[i].second.first == 'P')
            zliczp++;
        if(tab[i].second.first == 'M')
            zliczm++;
        if(tab[i].second.first == 'S')
            zliczs++;
    
        //cout<<ciag<<" ";
        if(i >1530){
            return 0;
        }
        int a = 0;
        if(tab[i].second.first == 'M'){
            a = 1;
            cout << "s['" << tab[i].second.second << "']=1;";
        }
        else if(tab[i].second.first == 'S') {
            a = 2;
            cout << "s['" << tab[i].second.second << "']=2;";
        }
        
        
    }
    
    return 0;
}


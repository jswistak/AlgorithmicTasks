#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;


int totrzym[100010];
int pojemnosc[100010];
int toczek[100010];
int testow;
int ile;
pair <int, int> t1[100010];
pair <int, int> t2[100010];
unsigned long long a, b;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> testow;
    for(int test = 0; test < testow; test++){
        cin >> ile;
        a = 0;
        b = 0;
        for(int i = 0; i < ile; i++){
            cin >> pojemnosc[i] >> totrzym[i] >> toczek[i];
            totrzym[i] = -totrzym[i];
            toczek[i] = -toczek[i];
            
            t1[i].first = totrzym[i];
            t1[i].second = totrzym[i] * pojemnosc[i];
            t2[i].first = toczek[i];
            t2[i].second = totrzym[i] * toczek[i];
            if(toczek[i] == totrzym[i]){
                i--;
                ile--;
                //nie potrzebujemy tego elementu
            }
        }
        for(int i = 0; i < ile; i++){
            a += abs(pojemnosc[i] * totrzym[i]);
            b += abs(pojemnosc[i] * toczek[i]);
            
        }
        if(a != b){
            cout << "NIE\n";
            continue;
        }
        string wynik = "NIE\n";
        //sprawdzamy czy najcieplejsza z a jest wieksza od najcieplejszej z b
        sort(t1, t1+ile);
        sort(t2, t2+ile);
        /*
        for(int i = 0; i < ile; i++){
            cout << t1[i].first << " ";
        }cout << endl;
        for(int i = 0; i < ile; i++){
            cout << t2[i].first << " ";
        }cout << endl;*/
        int licz = 0;
        while(licz < ile){
            if(t1[licz].first < t2[licz].first){
                wynik = "TAK\n";
            }
            else if(t1[licz].first == t2[licz].first){
                if(t1[licz].second < t2[licz].second){
                    wynik = "TAK\n";
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
            licz++;
        }
        cout << wynik;
    }
    
    return 0;
}

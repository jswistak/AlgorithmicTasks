#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <iomanip>
#define down first
#define up second
using namespace std;

using ll = long long;
const ll INF = 1e9L + 100;

pair<int, int> tab[1000200];
int n;
int wynik[1000100];
int najWynik = 0;
vector<pair<int, int>> up;
vector<pair<int, int>> down;

int szk(int wart){
    int beg = 0, end = up.size() - 1, mid;
    while (beg <= end) {
        mid = (beg + end) / 2;
        if(up[mid].first < wart){
            beg = mid + 1;
            //end = mid - 1;
        }
        else{
            end = mid - 1;
            //beg = mid + 1;
        }
    }
    if(beg >= up.size()){
        return -1;//error out of array
    }
    return beg;
}

int main() {
    cin.tie(0);cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tab[i].down >> tab[i].up;
    }
    up.push_back({-INF, n});
    down.push_back({INF, n});
    wynik[n - 1] = 1;
    up.push_back({tab[n - 1].up, n - 1});
    down.push_back({tab[n - 1].down, n - 1});
    
    for(int dzien = n - 2; dzien >= 0; dzien--){
        int wys = tab[dzien].down;
        while(down[down.size() - 1].first <= tab[dzien].down){
            down.pop_back();
        }

        
        int w = szk(wys);//na ktorym sie rozpierdole !
        //up[w].second powinno byc ~~
        ///~
        //cout << w;
        if(w != -1){
            while(up[w].first >= wys){
                w--;
            }
            w = up[w].second;
        }
        ///~
        /*
        int w = 0;
        for(int i = up.size() - 1; i >= 0; i--){
            cout << up[i].first<< " ";
            if(up[i].first < wys){
                //rozpierdole sie
                w = up[i].second;
                break;
            }
            
        }
         */
    //    cout << "<" << dzien << ", " << w << ">\n";cout << wys << " ";
    //   for(auto a : up)cout << a.first << " ";
        
        if(w == -1){
            wynik[dzien] = 1;
            //continue;
        }
        else if(w < down[down.size() - 1].second){
            wynik[dzien] = w - dzien;
            //cout<<"ups " << dzien;
        }
        else{
          //  cout << dzien << " " << down[down.size() - 1].second << "\n";
            wynik[dzien] = down[down.size() - 1].second - dzien + wynik[down[down.size() - 1].second];
            
        }
        while(up[up.size() - 1].first >= tab[dzien].up){
            up.pop_back();
        }
        if(tab[dzien].up >= up[up.size() - 1].first){
            up.push_back({tab[dzien].up, dzien});
        }
        if(tab[dzien].down <= down[down.size() - 1].first || down.size() == 0){
            down.push_back({tab[dzien].down, dzien});
        }
    }
    
    //wynik
    //cout << "\n\nWYNIK\n\n";
    for(int i = 0; i < n; i++){
      //  cout << "(" << i << " " << wynik[i] << ")\n";
        najWynik = max(najWynik, wynik[i]);
    }
    cout << najWynik;
}

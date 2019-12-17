#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <string>
#include <cstdio>


using namespace std;


map <string, int> element;
int ile;
string ciag;
string pomoc;
int brk = -1;

string substr (int a, int b){
    string str = "";
    for(int i = a; i < b; i++){
        str += ciag[i];
    }
    return str;
}



int main() {
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    cin >> ile;
    cin >> ciag;
    
    map<string, int>::iterator it;
    
    //dla kazdej dlugosc sprawdzaj czy mozna zrobic ciag dlugosci i
    for(int i = ile; i > 0; i--){
        for(int j = 0; j + i <= ile; j++){
            pomoc = substr(j, j + i );
            //element[pomoc] = 1;
            //cout<<pomoc<<endl;
            it = element.find(pomoc);
            if(brk != -1){
                continue;
            }
            else if(it != element.end() ){
                //element[pomoc] = 1;
                brk = i;
                //cout<<"Znalazlem";
            }
            else{
                element[pomoc] = 1;
                //cout<<"BREAK";
                //cout<<1;
            }
            
        }
    }
    //cout<<ciag;
    if(brk == -1){
        printf("1\n");
        //cout << 1 << "\n";
    }
    else{
        brk++;
        printf("%d", brk);
        //cout << brk + 1 << "\n";
    }
    //cout<<brk+1;
    return 0;
}

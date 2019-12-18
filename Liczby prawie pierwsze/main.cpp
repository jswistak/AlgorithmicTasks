#include <iostream>
#include <math.h>

using namespace std;
unsigned long long ile, a;
unsigned long long x;
int pierwsza[1000100];
double pot = 1 / 2;
void sito(){
    
    for(int i = 2; i < 1000; i++){
        if(pierwsza[i] == 0){
            for(int j = i * i; j < 1000010; j+=i){
                pierwsza[j] = 1;
            }
        }
    }
    
}
int main(int argc, const char * argv[]) {
    pierwsza[0] = 1;
    pierwsza[1] = 1;
    sito();
   /* for(int i = 1; i<100;i++){
        if(pierwsza[i] == 0){
            cout << i << " ";
        }
    }*/
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> ile;
    for(int i = 0; i < ile; i++){
        cin >> a;
        //x = sqrt(a);
        x = llround(sqrtl(a));
        if(x * x != a){
            x++;
            if(x * x != a){
                cout << "NIE\n";
                continue;
            }
        }
        if(pierwsza[x] == 0){
            cout << "TAK\n";
            continue;
        }
        
        cout << "NIE\n";
        
    }
    
    return 0;
}


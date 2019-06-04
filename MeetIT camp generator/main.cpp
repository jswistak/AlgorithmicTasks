#include <iostream>
#include <fstream>

using namespace std;
int n;
int tab[300][300];
char zn;
long long int score = 0;



void placequeen(int x, int y){
    tab[x][y] += 5 * n;
    if(1){//prawo i lewo
        for(int i = x + 1; i < n; i++){
            if(tab[i][y] == -1){
                break;
            }
            else{
                tab[i][y]++;
            }
        }
        for(int i = x - 1; i >= 0; i--){
            if(tab[i][y] == -1){
                break;
            }
            else{
                tab[i][y]++;
            }
        }
    }
    
    if(1){//gora i dol
        for(int i = y + 1; i < n; i++){
            if(tab[x][i] == -1){
                break;
            }
            else{
                tab[x][i]++;
            }
        }
        for(int i = y - 1; i >= 0; i--){
            if(tab[x][i] == -1){
                break;
            }
            else{
                tab[x][i]++;
            }
        }
        
    }
    if(1){//przekatne
        for(int i = 1; max(x + i, y + i) < n; i++){
            if(tab[x+i][y+i] == -1){
                break;
            }
            else{
                tab[x+i][y+i]++;
            }
        }
        for(int i = -1; min(x + i, y + i) >= 0; i--){
            if(tab[x+i][y+i] == -1){
                break;
            }
            else{
                tab[x+i][y+i]++;
            }
        }
        //teraz przekatne +- i -+
        int f = 1;
        while(x - f > 0 &&  y + f < n){
            f++;
            if(tab[x+f][y+f] == -1){
                break;
            }
            else{
                tab[x+f][y+f]++;
            }
        }
        f = 1;
        while(x + f < n && y - f >= 0){
            f++;
            if(tab[x+f][y+f] == -1){
                break;
            }
            else{
                tab[x+f][y+f]++;
            }
        }
    }
}
void removequeen(int x, int y){
    tab[x][y] -= 5 * n;
    if(1){//prawo i lewo
        for(int i = x + 1; i < n; i++){
            if(tab[i][y] == -1){
                break;
            }
            else{
                tab[i][y]--;
            }
        }
        for(int i = x - 1; i >= 0; i--){
            if(tab[i][y] == -1){
                break;
            }
            else{
                tab[i][y]--;
            }
        }
    }
    
    if(1){//gora i dol
        for(int i = y + 1; i < n; i++){
            if(tab[x][i] == -1){
                break;
            }
            else{
                tab[x][i]--;
            }
        }
        for(int i = y - 1; i >= 0; i--){
            if(tab[x][i] == -1){
                break;
            }
            else{
                tab[x][i]--;
            }
        }
        
    }
    if(1){//przekatne
        for(int i = 1; max(x + i, y + i) < n; i++){
            if(tab[x+i][y+i] == -1){
                break;
            }
            else{
                tab[x + i][y + i]--;
            }
        }
        for(int i = -1; min(x + i, y + i) > 0; i--){
            if(tab[x+i][y+i] == -1){
                break;
            }
            else{
                tab[x + i][y + i]--;
            }
        }
        //teraz przekatne +- i -+
        int f = 1;
        while(x - f >= 0 && y + f < n){
            f++;
            if(tab[x + f][y + f] == -1){
                break;
            }
            else{
                tab[x + f][y + f]--;
            }
        }
        f = 1;
        while(x + f < n && y - f >= 0){
            f++;
            if(tab[x + f][y + f] == -1){
                break;
            }
            else{
                tab[x + f][y + f]--;
            }
        }
    }
}
void queen(int x, int y, int sc){
    
    placequeen(x, y);
    for(int i = x + 1; i < n; i++){
        for(int j = 0; j < n; j++){
            if(tab[i][j] == 0){
                queen(i, j, sc + 1);
            }
        }
    }
    if(sc > score){
        cout << sc;
        remove("test.txt");
        ofstream outfile ("test.txt");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(tab[i][j] == -1){
                    outfile << "W";
                }
                else if(tab[i][j] == 5 * n){
                    outfile << "Q";
                }
                else{
                    outfile << "E";
                }
            }
            outfile << endl;
        }
        score = sc;
    }
    removequeen(x, y);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> zn;
            if(zn == 'W'){
                tab[i][j] = -1;
            }
            //E- empty
            //W- wall
            //0- if grater than 0 you cannot place queen
            
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(tab[i][j] == 0){
                queen(i, j, 1);
            }
        }
    }
    //outfile<<score;
    cout << score;
}

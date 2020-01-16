#include <iostream>
#include <algorithm>

#define INF 10000006
using namespace std;

long long tree[1500020];
long long taken;

unsigned long long score = 0;
long long powerOfTwo = 1;
long long height;
long long treeLast = 0;
int n;
void addToTree(int a){
    tree[a] = INF;
    while(a != 1){
        a /= 2;
        tree[a] = min(tree[a * 2], tree[a * 2 + 1]);
    }
    
}//dodaje wartosc inf w wierzcholku /A added value inf in vertex A
int look(int x){
    //powerOfTwo first index on the tree
    while(x < powerOfTwo){
        if(x * 2 >= powerOfTwo && x * 2 < treeLast){
            x *= 2;
            if(tree[x] == 0){
                addToTree(x);
                return 1;//succed
            }
            else if(tree[x + 1] == 0 && x + 1 < treeLast){
                addToTree(x + 1);
                return 1;//succed
            }
        }
        if(tree[x * 2] == 0){
            x *= 2;
            continue;
        }
        else{
            x *= 2;
            x++;
        }
    }
    if(tree[x] == 0 && x < treeLast){
        addToTree(x);
        return 1;
    }
    return 0;//fail
    
}
int checkInTree(int a){
    int b = treeLast - 1;
    while(a != b){
        if(a % 2 == 0 && tree[a + 1] == 0){
            return look(a + 1);
        }
        a /= 2;
        b /= 2;
    }
    return 0; //failed
}

pair <int,int> tab[1000020];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> height >> n;
    
    while(powerOfTwo < height){
        powerOfTwo *= 2;
    }
    
    
    for(int i = 0; i < n; i++){
        cin >> tab[i].first >> tab[i].second;//first value; second weight
        tab[i].first = -tab[i].first;
        tab[i].second = -tab[i].second;
        
    }
    
    sort(tab, tab + n);
    
    treeLast = powerOfTwo + height;
    
    for(int i = 0; i < n; i++){
        tab[i].first = -tab[i].first;
        tab[i].second = -tab[i].second;
    }
    for(int i = 0; i < n; i++){
        if(tab[i].second <= height){
            if(tree[tab[i].second + powerOfTwo - 1] == 0){
                addToTree(tab[i].second + powerOfTwo - 1);
                score += tab[i].first;
            }
            else if(checkInTree(tab[i].second + powerOfTwo - 1)){
                score += tab[i].first;
            }
            
            
            
        }
    }
    cout << score ;
    return 0;
}


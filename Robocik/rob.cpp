#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long getint(){
    long long temp=0;char c;
    
    do{
        c=getchar_unlocked();
    }while(c<'0' || c>'9');
    do{
        temp=temp*10+c-'0';
        c=getchar_unlocked();
    }while(c>='0' && c<='9');
    
    
    return temp;
}

vector< pair<long long,long long> > cononx[1000001];
vector< pair<long long,long long> > conony[1000001];

long long maksy,maksx,minx,miny;
map <long long,long long > mapax;//pointery na vectory zawierajace proste o wsp x //jesli jest tu to break na y
map <long long,long long> mapay;//pointery na vectory zawierajace proste o wsp y
long long obecny,cykl;
unsigned long long wynik=0;
long long czas;
long long n,x,y;
long long tab[1000001];
vector <long long> tempx;
vector <long long> tempy;
pair <long long, long long> point[1000020];//drogarobota
pair <long long, long long> przesuniecie;
long long syf,syf2;

int pktnaprzedziale(){
    if(przesuniecie.first>0){
        if(minx>x){
            return 0;
            //cout<<"ala";
        }
    }
    //cout<<przesuniecie.second;
    if(przesuniecie.second>0){
        if(miny>y){
            return 0;
        }
    }
    if(przesuniecie.first<0){
        if(maksx<x){
            return 0;
        }
    }
    if(przesuniecie.second<0){
        if(maksy<y){
            return 0;
        }
    }
    return 1;
}

int main(){
    n=getint();
    czas=getint();
    int ile=n*4;
    for(int i=0;i<n;i++){
        tab[i]=getint();
        cykl+=tab[i];
    }
    cykl*=4;
    cykl+=(n*4);
    //cout<<cykl<<endl;
    //for(int i=0;i<ile;i++)cout<<tab[i%n]<<" ";
    for(int i=0;i<ile;i++){
        //cout<<tab[i%n]<<" ";
        if(i%4==0){
            y+=tab[i%n];
        }
        else if(i%4==1){
            x+=tab[i%n];
        }
        else if(i%4==2){
            y-=tab[i%n];
        }
        else if(i%4==3){
            x-=tab[i%n];
        }
        minx=min(minx,x);
        miny=min(miny,y);
        maksy=max(maksy,y);
        maksx=max(maksx,x);
        //cout<<"dodano "<<x<<" "<<y<<" .";
        point[i+1]=make_pair(x,y);
        tempy.push_back(y);
        tempx.push_back(x);
        
    }//cout<<endl;
    //cout<<x<<y;
    
    //return 0;
    
    przesuniecie=make_pair(x,y);
    //cout<<"przesuniecie"<<x<<" "<<y;
    
    //Opracowanie szukanych pkt
    //cout<<przesuniecie.first<<" "<<przesuniecie.second;
    scanf("%lld%lld",&x,&y);
    
    /*
     for(int i=0;i<=ile;i++){
     cout<<"("<<point[i].first<<","<<point[i].second<<") ";
     }
     */
    //cout<<przesuniecie.first<<" "<<przesuniecie.second<<endl;
    if(przesuniecie.first==0 && przesuniecie.second==0){
        //return 0;
        //Nie mamy przesuniecia
        //cout<<"xxxxxx";
        //if(x==0 && y==0)wynik++;
        for(int i=0;i<=ile;i++){
            if(point[i].first==point[i+1].first && point[i].first==x){
                if(max(point[i].second,point[i+1].second)>=y && min(point[i].second,point[i+1].second)<=y){
                    wynik++;
                }
            }
            else if(point[i].second==point[i+1].second && point[i].second==y){
                if(max(point[i].first,point[i+1].first)>x && min(point[i].first,point[i+1].first)<x){
                    wynik++;
                }
            }
            
        }
        //int t=1;
        //cout<<"ala "<<wynik<<" ala "<< czas<<"/"<<cykl<<" "<<czas/cykl<<endl;
        if(x==0 && y==0){
            wynik--;
        }
        wynik=wynik*(czas/cykl);
        czas%=cykl;
        if(czas==0 && x==0 && y==0){
            wynik++;
        }
        //mamy czas//policzyc wynik z zero i symulacja dalej
        
        if(czas>=1){//////////////////////////////////////////Tu moze byc >1 ??
            if(x==0 && y==0)wynik++;//zakladam ze nalezy
            for(int i=0;i<=ile;i++){
                if(point[i].first==point[i+1].first && point[i].first==x){
                    if(max(point[i].second,point[i+1].second)>y && min(point[i].second,point[i+1].second)<y){
                        if(czas-abs(point[i].second-y)>=0)
                            wynik++;
                    }
                }
                else if(point[i].second==point[i+1].second && point[i].second==y){
                    if(max(point[i].first,point[i+1].first)>=x && min(point[i].first,point[i+1].first)<=x){
                        if(czas-abs(point[i].first-x)>=0)
                            wynik++;
                    }
                }
                
                czas-=(abs(point[i].first-point[i+1].first+point[i].second-point[i+1].second)+1);
                
            }
            
        }
        cout<<wynik<<"\n";
        return 0;
    }
    
    else{//przesuniecie !=0
        //cout<<"AAAA";
        sort(tempx.begin(),tempx.end());
        long long indeksa=1,indeksb=1;
        mapax.insert( make_pair(tempx[0],indeksa));
        mapay.insert( make_pair(tempy[0],indeksb));
        indeksb++;
        indeksa++;
        for(int i=1;i<tempx.size();i++){
            if(tempx[i]!=tempx[i-1]){
                mapax.insert(make_pair(tempx[i],indeksa));
                indeksa++;
            }
            if(tempy[i]!=tempy[i-1]){
                mapay.insert(make_pair(tempy[i],indeksb));
                indeksb++;
            }
        }
        //cout<<endl<<endl;
        int pointera,pointerb;
        //cout<<point[0].first<<" "<<point[0].second;
        for(int i=0;i<ile;i++){
            //wkladnie odcinkow x-y na vectory par
            //cononx
            //conony
            if(i%4==2){
                // dodaj na y
                pointera=mapax.find(point[i].first)->second;
                cononx[pointera].push_back(make_pair(point[i].second,point[i+1].second));
            }
            else if(i%4==3){
                pointerb=mapay.find(point[i].second)->second;
                conony[pointerb].push_back(make_pair(point[i].first,point[i+1].first));
            }
            else if(i%4==0){
                pointera=mapax.find(point[i].first)->second;
                cononx[pointera].push_back(make_pair(point[i+1].second,point[i].second));
            }
            else{
                pointerb=mapay.find(point[i].second)->second;
                conony[pointerb].push_back(make_pair(point[i+1].first,point[i].first));
            }
            
            
        }
        
        //cout<<x<<" "<<y<<endl;
        //cout<<"Czas"<<czas<<" cykl"<<cykl<<endl;
        
        while(pktnaprzedziale() && (czas-cykl)>=0){//////////////////////////
            
            czas-=cykl;
            //cout<<"+";
            //sprawdz czy jest na przedziale
            //pointera=mapax.find(x)->second;
            //pointerb=mapay.find(y)->second;
            if(mapax.find(x)!=mapax.end()){//if exist
                //cout<<"h"; //dziala
                pointera=mapax.find(x)->second;
                for(int i=0;i<cononx[pointera].size();i++){
                    //interesuje mnie tylko y
                    //cout<<cononx[pointera][i].first<<">="<<y<<" && "<<cononx[pointera][i].second<<"<="<<y<<endl;
                    if(cononx[pointera][i].first>=y && cononx[pointera][i].second<=y){
                        wynik++;
                        //cout<<"A";
                        //cout<<x<<" "<<y<<"A";
                    }
                }
                //szukaj na x//TODO
            }
            if(mapay.find(y)!=mapay.end()){
                //cout<<"l";// dziala
                pointerb=mapay.find(y)->second;
                for(int i=0;i<conony[pointerb].size();i++){
                    //cout<<conony[pointerb][i].first<<">"<<y<<" && "<<conony[pointerb][i].second<<"<"<<y<<endl;
                    if(conony[pointerb][i].first>x && conony[pointerb][i].second<x ){
                        wynik++;
                        //cout<<"B";
                        //cout<<x<<" "<<y<<"B";
                    }
                }
                
            }
            //if(x==0 && y==0)wynik--;
            
            //koniec sprawdz na przedziale
            x-=przesuniecie.first;
            y-=przesuniecie.second;
        }
        //cout<<wynik<<"A";
        //cout<<" "<<czas<<" "<<endl;
        if(czas>=1){
            if(x==0 && y==0)wynik++;//zakladam ze nalezy
            for(int i=0;i<=ile;i++){
                if(point[i].first==point[i+1].first && point[i].first==x){
                    if(max(point[i].second,point[i+1].second)>y && min(point[i].second,point[i+1].second)<y){
                        if(czas-abs(point[i].second-y)>=0)
                            wynik++;
                    }
                }
                else if(point[i].second==point[i+1].second && point[i].second==y){
                    if(max(point[i].first,point[i+1].first)>=x && min(point[i].first,point[i+1].first)<=x){
                        if(czas-abs(point[i].first-x)>=0)
                            wynik++;
                    }
                }
                
                czas-=(abs(point[i].first-point[i+1].first+point[i].second-point[i+1].second)+1);
                
            }
            
            
        }
        cout<<wynik<<"\n";
        return 0;
        //x map add when const x
        //y add when const y
        
        //szukaj punktu x,y i sprawdzaj czas
        
        // when x1-x2 contain point w++
        // when presuniecie is in other direction break
        // else continue
        // when point lim border add jump pointers
        //cout<<mapax.size();
        //cout<<mapay.size();
        //cout<<tempx.size()<<tempy.size();
        
        
    }
    
    return 0;
}

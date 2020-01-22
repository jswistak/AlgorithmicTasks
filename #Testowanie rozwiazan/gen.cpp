#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]){
	srand(atoi(argv[1]));
	int miast = 1 + rand() % 6000;
    int miejsc = 1 + rand() % 6000;
    int zgloszen = 1 + rand() % 6000;
    cout << miast << " " << miejsc << " " << zgloszen << "\n";
    
    for(int i = 0; i < zgloszen; i++){
        int a = 1 + rand() % miast;
        int b = 1 + rand() % miast;
        int c = 1 + rand() % miejsc;
        if(a <= b){
            cout << a << " " << b << " " << c << "\n";
        }
        else{
            cout << b << " " << a << " " << c << "\n";
        }
    }
    
    
	return 0;
}


#include <iostream>

using namespace std;

int m, n, tab[1010][1010];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> tab[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
	   for(int j = 1; j <= m; j++){
		tab[i][j] += tab[i - 1][j] + tab[i][j - 1];   
	   }
	}
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}	




}

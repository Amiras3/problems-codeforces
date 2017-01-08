#include <iostream>
#include <algorithm>
#include <vector>

using namespace std ;

int ma[109][109] , n , m , q ;
int col[109] , lin[109] ;
void coloana(int i){
	for(int j = 1 ; j <= n ; j ++){
		col[j] = ma[j][i] ;
	}
	for(int j = 1 ; j <= n - 1; j ++){
		ma[j + 1][i] = col[j]  ;
	}
	ma[1][i] = col[n] ;
}

void linie(int i){
	for(int j = 1 ; j <= m ; j ++){
		lin[j] = ma[i][j] ;
	}
	for(int j = 1 ; j <= m - 1 ; j ++){
		ma[i][j + 1] = lin[j] ;
	}
	ma[i][1] = lin[m] ;
}
int main(){
	int q , query[10009][4] ;
	cin >> n >> m >> q ;
	for(int i = 1 ; i <= q ; i ++){
		cin >> query[i][0] ;
		if(query[i][0] == 1 || query[i][0] == 2){
			cin >> query[i][1] ;
		}
		if(query[i][0] == 3){
			cin >> query[i][1] >> query[i][2] >> query[i][3] ;
		}
	}
	for(int i = q ; i >= 1 ; i --){
		if(query[i][0] == 1){
			linie(query[i][1]) ;
		}
		if(query[i][0] == 2){
			coloana(query[i][1]) ;
		}
		if(query[i][0] == 3){
			ma[query[i][1]][query[i][2]] = query[i][3] ;
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= m ; j ++){
			cout << ma[i][j] << " " ;
		}
		cout << "\n" ;
	}
	return 0 ;
}




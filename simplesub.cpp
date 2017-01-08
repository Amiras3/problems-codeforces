#include <iostream>
using namespace std ;

int ciur[2000009] ;

void umple(){
	for(int i = 2 ; i * i <= 2000000 ; i ++){
		if(ciur[i] == 0){
			for(int j = i ; j * i <= 2000000 ; j ++){
				ciur[i * j] = 1 ;
			}
		}
	}
	ciur[1] = 1 ;
}

int main(){
	umple() ;
	int n , vect[1009] ;
	cin >> n ;
	for(int i = 1 ; i <= n ; i ++){
		cin >> vect[i] ;
	}
	int n1 = 0 ;
	for(int i = 1 ; i <= n ; i ++){
		if(vect[i] == 1){
			n1 ++ ;
		}
	}
	if(n1 >= 2){
		int i ;
		for(i = 1 ; i <= n ; i ++){
			if(vect[i] != 1 && ciur[vect[i] + 1] == 0){
				break ;
			}
		}
		if(i != n + 1){
			cout << n1 + 1 ;
			cout << endl ;
			for(int j = 1 ; j <= n1 ; j ++){
				cout << "1 " ;
			}
			cout << vect[i] ;
			return 0 ;
		}
		else{
			cout << n1 ;
			cout << endl ;
			for(int j = 1 ; j <= n1 ; j ++){
				cout << "1 " ;
			}
			return 0 ;
		}
	}
	else{
		int ok = 0 , ok1 = 0 , ind , ind1 , ind2 ;
		for(int i = 1 ; i <= n ; i ++){
			if(ciur[vect[i]] == 0){
				ok1 = 1 ;
				ind = i ;
			}
			for(int j = i + 1 ; j <= n ; j ++){
				if(ciur[vect[j] + vect[i]] == 0){
					ok  = 1 ;
					ind1 = i ;
					ind2 = j ;
				}
			}
		}
		if(ok == 1){
			cout << "2" << endl ;
			cout << vect[ind1] << " " << vect[ind2] ;
			return 0 ;
		}
		else{
			if(ok1 == 1){
				cout << "1" << endl ;
				cout << vect[ind] ;
				return 0 ;
			}
			else{
				cout <<  "1" ;
				cout << endl << vect[1] ;
				return 0 ;
			}
		}
	}
	return 0 ;
}

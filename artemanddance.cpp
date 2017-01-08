#include <iostream>
#include <fstream>
#include <math.h>
#include <unordered_map>
using namespace std ;

int n ;
int ok = 1 ;
int a[1000009] ;
int main(){
	int q , x , add_even = 0 , add_odd = 0 , c;
	scanf("%d%d" , &n , &q) ;
	for(  ; q != 0 ; q --){
		scanf("%d" , &c) ;
		if(c == 1){
			scanf("%d" , &x) ;
			add_even =(add_even +  x + n) % n ;
			add_odd = (add_odd + x + n ) % n ;
			if(x < 0){
				x = - x ;
			}
			if(x % 2 == 1){
				ok = 1 - ok ;
			}
		}
		if(c == 2){
			if(ok == 1){
				add_even = (add_even - 1 + n) % n ;
				add_odd = (add_odd + 1) % n;
				ok = 0 ;
			}
			else{
				add_even = (add_even + 1) % n ;
				add_odd = (add_odd - 1 + n) % n;
				ok = 1 ;
			}
		}
	}
	for(int i = 1 ; i <= n/2 ; i ++){
		a[(2 * i + add_even - 1 + n) % n + 1] = 2 * i ;
		a[(2 * i - 1 + add_odd - 1 + n) % n + 1] = 2 * i - 1;
	}
	for(int i = 1 ; i <= n ; i ++){
		printf("%d " , a[i]) ;
	}
	return 0 ;
}


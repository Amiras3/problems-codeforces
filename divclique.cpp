#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std ;

int ap[1000000 + 10] ;

int main(){
	int n , a[1000000 + 10] , dp[1000000 + 10] ;
	scanf("%d" , &n) ;
	for(int i = 1 ; i <= n ; i ++){
		scanf("%d" , &a[i]) ;
		ap[a[i]] = i ;
	}
	for(int i = 1 ; i <= n ; i ++){
		dp[i] = 1 ;
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 2 * a[i] ; j <= 1000000 ; j += a[i]){
			if(ap[j]){
				dp[ap[j]] = max(dp[ap[j]] , dp[i] + 1) ;
			}
		}
	}
	int sol = 0 ;
	for(int i = 1 ; i <= n ; i ++){
		sol = max(sol , dp[i]) ;
	}
	printf("%d" , sol) ;
	return 0 ;
}

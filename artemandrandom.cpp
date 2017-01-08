#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
using namespace std ;

int main(){
	long long n ;
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin >> n ;
	double p[n + 10] , q[n + 10] , max[n + 10] , min[n + 10] ;
	for(int i = 1 ; i <= n ; i ++){
		cin >> max[i] ;
	}
	for(int i = 1 ; i <= n ; i ++){
		cin >> min[i] ;
	}
	double delta = (max[1] + min[1]) * (max[1] + min[1]) - 4 * max[1] ;
	if(delta < 0){
		delta = 0 ;
	}
	p[1] = (max[1] + min[1] + sqrt(delta)) / 2 ;
	q[1] = min[1] + max[1] - p[1] ;
	double sum_p = p[1]  , sum_q = q[1] ;
	for(int i = 2 ; i <= n - 1 ; i ++){
		delta = (max[i] + min[i] + sum_q - sum_p)*(max[i] + min[i] + sum_q - sum_p) + 4*(max[i] * sum_p + min[i] * sum_p - max[i]) ;
		if(delta < 0){
			delta = 0 ;
		}
		p[i] = ((max[i] + min[i] + sum_q - sum_p) + sqrt(delta)) / 2 ;
		q[i] = max[i] + min[i] - p[i] ;
		sum_q += q[i] ;
		sum_p += p[i] ;
	}
	if(n != 1){
	p[n] = 1 - sum_p ;
	q[n] = 1 - sum_q ;
	}
	for(int i = 1 ; i <= n ; i ++){
		printf("%.6lf " , p[i]) ;
	}
	printf("\n") ;
	for(int i = 1 ; i <= n ; i ++){
		printf("%.6lf " , q[i]) ;
	}
	return 0 ;
}

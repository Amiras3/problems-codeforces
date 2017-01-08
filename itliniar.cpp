#include<iostream>
#include<map>
#include<vector>

using namespace std;

const long long mod = 1000000000 + 7;

long long power(long long x , long long y){
	long long p = 1;
	while(y){
		if(y & 1){
			p = (p * x) % mod;
		}
		x = (x * x) % mod;
		y /= 2;
	}
	return p;
}

int main(){
	long long a , b , x , n;
	cin >> a >> b >> n >> x;
	if(a == 1){
		n = n % mod;
		long long res = (b  * n) % mod;
		res = (res + x)% mod;
		cout << res;
		return 0;
	}
	long long res = power(a, n);
	res = (res * x) % mod;
	long long term = b;
	term = (power(a - 1, mod - 2) * term) % mod;
	long long term2 = power(a, n);
	term2 = (term2 + mod - 1) % mod;
	term = (term * term2) % mod;
	res = (res + term) % mod;
	cout << res ;
}

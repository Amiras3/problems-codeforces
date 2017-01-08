#include<iostream>

using namespace std;

const int Max = 1000000;

int n, k, a[Max];
int sir[Max];
int lef;
void read(){
	cin >> n >> k;
	for(int i = 1 ; i <= n ;i++){
		int x;
		cin >> x;
		sir[i] = x;
		if(!x){
			a[i] = a[i - 1] + 1;
		}
		else{
			a[i] = a[i - 1];
		}
	}
}

int solve(){
	int rez = 0;
	for(int l = 0, r = 1; l < n; l++){
		while(r <= n && a[r] - a[l] <= k){
			r++;
		}
		if(rez <r - l - 1){
			rez=r-l-1;
			lef=l+1;
		}
	}
	return rez;
}

int main(){
	read();
	int rez = solve();
	for(int i = 0 ; i < rez;i++){
		sir[i + lef] = 1;
	}
	cout<<rez<<endl;
	for(int i = 1; i <=n;i++){
		cout << sir[i]<< " ";
	}
	return 0;
}

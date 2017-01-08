#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<math.h>

using namespace std;
const int Max = 100000 + 10;

int main(){
	int n ;
	int r[Max], l[Max];
	cin >> n; int i1 = 0 , i2 = 0;
	int sum = 0 , min = Max * 600, max = -Max * 600;
	for(int i = 1 ; i <= n ;i++){
		cin >> l[i] >> r[i];
		sum +=(l[i] - r[i]);
		if(r[i] - l[i]< min){
			min= r[i]-l[i];
			i1 = i;
		}
		if(r[i]-l[i]>max){
			max=r[i]-l[i];
			i2=i;
		}
	}
	int n1 = fabs(sum) ,n2 = fabs(sum + 2 * max), n3 = fabs(sum + 2*min);
	if(n1 >= n2 && n1 >= n3){
		cout << '0';
		return 0;
	}
	if(n2 >= n3){
		cout << i2 ;
		return 0;
	}
	cout << i1;
	return 0;
}

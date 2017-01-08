#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

long long n, k;
long long b[600] , a[600] ;
map<long long , int> m;
vector<long long> index;

void read(){
	cin >> n;
	long long sum = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum+=a[i];
		m[sum] = i;
	}
	cin >> k;
	for(int i = 1 ; i <= k; i++){
		cin >> b[i];
	}
}

bool check(){
	long long sum = 0;
	for(int i = 1 ; i <= k ;i++){
		sum += b[i];
		if(m.find(sum) == m.end()){
			return false ;
		}
		else{
			index.push_back(m[sum]);
		}
	}
	if(m[sum] != n){
		return false;
	}
	return true;
}

bool check_vector(int index1 , int index2){
	if(index1 == index2){
		return true;
	}
	int max = 0;
	for(int i =index1; i <= index2; i++){
		if(a[i] > max){
			max = a[i];
		}
	}
	for(int i = index1 ; i <= index2; i++){
		if(a[i] != max){
			return true;
		}
	}
	return false;
}

bool check2(){
	index.insert(index.begin(), 0);
	for(int i = 0; i < index.size() -1; i++){
		if(check_vector(index[i] + 1 ,index[i+1]) == false){
			return false;
		}
	}
	return true;
}

void afis(int ind1, int ind2, int count){
	if(ind1 == ind2){
		return;
	}
	int max = 0;
	for(int i = ind1; i<=ind2; i++){
		if(a[i] > max){
			max = a[i];
		}
	}
	int ind = 0;
	for(int i = ind1 + 1; i <= ind2; i++){
		if(a[i - 1] != max && a[i] == max){
			ind = i;
		}
	}
	if(ind != 0){
		for(int i = ind - ind1 + 1 + count; i >= count + 2; i--){
			cout << i << " L" << '\n';
		}
		for(int i = 1; i <= ind2 - ind; i++){
			cout << count + 1 << " R" << '\n';
		}
		return;
	}
	for(int i = ind1; i < ind2; i++){
		if(a[i] == max && a[i +1] != max){
			ind = i;
		}
	}
	for(int i = ind ; i < ind2 ; i++){
		cout << ind -  ind1 + 1 + count << " R"<< '\n';
	}
	for(int i = ind - ind1 + 1 + count; i >= count + 2 ; i--){
		cout << i << " L" << '\n';
	}
}

int main(){
	read();
	if(!check()){
		cout << "NO" << '\n';
		return 0;
	}
	if(!check2()){
		cout << "NO" << '\n';
		return 0;
	}
	cout << "YES" << '\n';
	int count = 0;
	for(int i = 0; i < index.size() - 1; i++){
		afis(index[i] + 1 , index[i + 1], count);
		count++;
	}
	return 0;
}

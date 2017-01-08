#include<iostream>
#include<string>
#include<vector>

using namespace std;
const int Max = 200000 + 10;

void read(int &n, string &s){
	cin >> n >> s;
}

int solve(string s){
	string s1 = s + s;
	int size = s.size();
	vector<int> elim(s1.size() + 3 , 0);
	int r1 = 1;
	int r2 = 1;
	for(int i = 0; i < size; i++){
		if(s[i] == 'D' && !elim[i]){
			r1 = max(r1, i + 1);
			while((r1 < s1.size() && s1[r1] != 'R') || elim[r1]){
				r1++;
			}
			if(r1 == s1.size()){
				return 1;
			}
			elim[r1 % size] = 1;
			elim[r1 % size + size] = 1;
		}
		if(s[i] == 'R' && !elim[i]){
			r2 = max(r2, i + 1);
			while((r2 < s1.size() && s1[r2] != 'D') || elim[r2]){
				r2++;
			}
			if(r2 == s1.size()){
				return 2;
			}
			elim[r2 % size] = 1;
			elim[r2 % size + size] = 1;
		}
	}
	string s2;
	for(int i = 0; i < s.size(); i++){
		if(elim[i] == 0){
			s2.push_back(s[i]);
		}
	}
	return solve(s2);
}

int main(){
	int n;
	string s;
	read(n, s);
	int res = solve(s);
	if(res == 1){
		cout << 'D';
	}
	else{
		cout << 'R';
	}
	return 0;
}

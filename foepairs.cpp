#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stdio.h>
#include<set>

using namespace std;

const int Max = 3 * 100000 + 5;
int  n, m;
int p[Max], index[Max];
vector<multiset<int>> foe(Max);

void read(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &p[i]);
		index[p[i]] = i;
	}
	for(int i = 1; i <= m; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		foe[a].insert(index[b]);
		foe[b].insert(index[a]);
	}
}

bool check(int l, int r){
	auto it = foe[p[r]].lower_bound(l);
	if(it != foe[p[r]].end() && *it < r){
		return false;
	}
	return true;
}

long long count(){
	long long res = 0;
	for(int i = 1, r = 1; i <= n; i++){
		r++;
		r = max(r, i + 1);
		while(r <= n && check(i, r)){
			r++;
		}
		r--;
		res += 1LL * (r - i + 1);
	}
	return res;
}

int main(){
	read();
	cout << count();
}

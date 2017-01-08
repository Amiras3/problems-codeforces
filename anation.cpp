#include<iostream>
#include<vector>

using namespace std;

int n, m, k;
vector<int> g;
vector<vector<int>> edges(100000 + 10);
vector<vector<int>> city(100000 + 10);
int visited[100000 + 10];
vector<int> f;

void read(){
	cin >> n >> m >> k;
	for(int i = 1 ; i <= k ;i++){
		int c;
		cin >> c;
		g.push_back(c);
	}
	for(int i = 1; i <= m ; i++){
		int x, y;
		cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
}

void dfs(int x , vector<int> &v){
	visited[x] = 1;
	v.push_back(x);
	for(int node : edges[x]){
		if(!visited[node]){
			dfs(node , v);
		}
	}
}

int num(vector<int> v){
	int res = 0;
	for(int i : v){
		res += edges[i].size();
	}
	return res/2 ;
}

void dfs1(){
	int num = 1;
	for(int i : g){
		dfs(i , city[num]);
		num++;
	}
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			f.push_back(i);
		}
	}
}

int solve(){
	int max_size = 0;
	for(int i = 0; i < city.size(); i++){
		int size = city[i].size();
		max_size = max(max_size, size);
	}
	int res = max_size * f.size();
	for(int i = 1 ; i <= k ;i++){
		res += (city[i].size() * (city[i].size() - 1))/2 - num(city[i]);
	}
	res += (f.size() * (f.size()- 1))/2 - num(f);
	return res;
}

int main(){
	read();
	dfs1();
	cout << solve();
}

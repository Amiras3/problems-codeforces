#include<iostream>
#include<map>
#include<vector>

using namespace std;

const int Max = 2000;
const float inf = 47474859;
int n;
vector<pair<double, double>> pairs;
map<pair<double, double>, long long> m;

void read(){
	cin >> n;
	for(int i = 1 ; i <= n; i++){
		double x , y ;
		cin >> x >> y;
		pairs.push_back(make_pair(x, y));
	}
}

int solve(){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			double panta;
			if(pairs[i].first == pairs[j].first){
				panta = inf;
			}
			else{
				panta = (pairs[j].second - pairs[i].second)/(pairs[j].first - pairs[i].first);
			}
			double lung = 1LL * (pairs[j].second - pairs[i].second) *(pairs[j].second - pairs[i].second);
			lung += 1LL * (pairs[j].first -pairs[i].first) * (pairs[j].first - pairs[i].first);
			m[make_pair(panta , lung)]++;
		}
	}
	long long res = 0;
	for(auto it = m.begin(); it != m.end(); it++){
		int numb = it->second;
		if(numb >= 2){
			res += (1LL * numb * (numb - 1))/2;
		}
	}
	return res / 2;
}

int main(){
	read();
	cout << solve();
	return 0;
}

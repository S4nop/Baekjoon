#include <bits/stdc++.h>

using namespace std;
vector<int> crane_power;
multiset<int> stuff;

int main(){
	ios_base::sync_with_stdio(0);
	int N, M, tmp;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> tmp;
		crane_power.emplace_back(tmp);
	}
	cin >> M;
	for (int i = 0; i < M; i++){
		cin >> tmp;
		stuff.insert(tmp);
	}

	sort(crane_power.begin(), crane_power.end());
	auto siter = stuff.end();
	if (crane_power[N-1] < *(--siter)){
		cout << -1;
		return 0;
	}
	int chk, time = 0;
	while (!stuff.empty()){
		++time;
		for (int crane : crane_power){
			if (stuff.empty()) break;
			auto it = stuff.find(crane);
			if (it != stuff.end()){
				stuff.erase(it); continue;
			}
			if ((it = stuff.lower_bound(crane)) == stuff.begin()) continue;
			stuff.erase(--it);
		}
	}
	cout << time;
}
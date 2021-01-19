#include <bits/stdc++.h>

using namespace std;

int tt[200200];

int main(){
	ios_base::sync_with_stdio(0);
	multiset<pair<int, int>> dt;
	int s, t, N, j = 0;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> s >> t;
		dt.insert(make_pair(s, t));
	}

	while(!dt.empty()){
		multiset<pair<int, int>>::iterator targ;
		while((targ = dt.upper_bound(make_pair(tt[j], 0))) != dt.end()){
			tt[j] = (*targ).second;
			dt.erase(targ);
		}
		++j;
	}

	cout << j;
}
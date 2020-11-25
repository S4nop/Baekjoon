#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	vector<long long> rope;
	long long N, r, ans;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> r;
		rope.push_back(r);
	}
	sort(rope.begin(), rope.end(), greater<long long>());

	r = 1;
	ans = 0;
	long long bef = -999999;
	for (auto &n : rope){
		bef = max(bef, n * r++);
	}
	cout << bef;
}
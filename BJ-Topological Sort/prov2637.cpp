#include <bits/stdc++.h>

using namespace std;
int partsnum[110];
vector<pair<int, int>> parts[110];
queue<pair<int, int>> q;
int main(){
	ios_base::sync_with_stdio(0);
	int N, M, x, y, k, i;
	cin >> N >> M;
	for (i = 0; i < M; i++){
		cin >> x >> y >> k;
		parts[x].push_back(make_pair(y, k));
	}

	q.push(make_pair(N, 1));
	while (!q.empty()){
		x = q.front().first;
		y = q.front().second;
		partsnum[x] += y;
		q.pop();
		for (pair<int, int> p : parts[x]){
			q.push(make_pair(p.first, p.second * y));
		}
	}

	for (i = 1; i <= N; i++){
		if (!parts[i].size()) cout << i << " " << partsnum[i] << "\n";
	}
}
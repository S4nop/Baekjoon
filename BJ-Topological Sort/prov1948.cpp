#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> road[10100];
int start, dest, dist[10100], mx, ans;
bool visited[10100] = { 0, };
vector<int> vecTmp;
set<int> stAll;
void bTrack(int now, int d){
	if (dist[now] == d && now == dest){
		for (int v : vecTmp){
			if (stAll.count(v)) continue;
			stAll.insert(v);
			ans++;
		}
	}

	for (auto &v : road[now]){
		if (dist[v.second & 0x3fff] == d + v.first){
			vecTmp.push_back(v.second >> 14);
			bTrack(v.second & 0x3fff, d + v.first);
			vecTmp.pop_back();
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	int n, m, i, j, t;
	cin >> n >> m;
	for (i = 0; i < m; i++){
		cin >> start >> dest >> t;
		road[start].push_back(make_pair(t, dest + (i << 14)));
	}
	cin >> start >> dest;

	priority_queue<pair<int, int>> pq;
	memset(dist, -1, sizeof(dist));
	pq.push(make_pair(0, start));

	while (!pq.empty()){
		do{
			i = pq.top().first;
			j = pq.top().second & 0x3fff;
			pq.pop();
		} while (!pq.empty() && visited[j]);
		if (visited[j]) break;
		visited[j] = 1;
		for (auto &v : road[j]){
			if (dist[v.second & 0x3fff] < i + v.first) {
				dist[v.second & 0x3fff] = i + v.first;
				pq.push(make_pair(i + v.first, v.second));
			}
		}
	}

	mx = dist[dest];
	bTrack(start, 0);
	cout << mx << "\n" << ans;
}
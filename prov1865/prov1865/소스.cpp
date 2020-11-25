#include <cstdio>                                                                                    
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define INF 10000000

using namespace std;
typedef pair<int, int> p;
queue<int> q;
vector<p> adj[505];
bool cango;
int dist[505], chk[505], chkvs;
void ClearQ(queue<int> &q){
	queue<int> empty;
	swap(q, empty);
}
int main(){
	ios_base::sync_with_stdio(0);
	int T, i, N, M, W, s, e, t;
	cin >> T;
	while (T-- != 0){
		cin >> N >> M >> W;
		fill(dist, dist + 505, INF);
		fill(chk, chk + 505, 0);
		chkvs = 0;
		cango = 0;
		for (i = 0; i < 505; i++)
			adj[i].clear();
		ClearQ(q);
		for (i = 0; i < M; i++){
			cin >> s >> e >> t;
			if (e == 1) cango = true;
			adj[s - 1].push_back(p(e - 1, t));
		}
		for (i = 0; i < W; i++){
			cin >> s >> e >> t;
			if (e == 1) cango = true;
			adj[s - 1].push_back(p(e - 1, -t));
		}
		dist[0] = 0;
		if (!cango) goto n;
		q.push(0);
		chk[0] = 1;
		int tmp;
		while (!q.empty()){
			tmp = q.front();
			if (++chkvs > N * N) { cout << "YES\n"; break; }
			q.pop();
			chk[tmp] = 0;
			for (auto &u : adj[tmp]){
				int n = u.first, w = u.second;
				if (dist[n] > dist[tmp] + w  && w != INF){
					dist[n] = dist[tmp] + w;
					if (chk[n]) continue;
					chk[n] = 1;
					q.push(n);
				}
			}
		}
	n:
		if (chkvs <= N * N) cout << "NO\n";
	}
}
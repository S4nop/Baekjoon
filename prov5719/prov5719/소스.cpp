#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <stack>
#define Max_v 505
#define INF 2100000000
using namespace std;

typedef pair<int, int> p;
vector<int> rslt;
vector<p> adj[Max_v];
int dist[Max_v], d;
bool ddd[Max_v][Max_v];
bool visited[Max_v];
int minsum;
priority_queue<p, vector<p>, greater<p>> pq;
vector<p> stk;

int dfs(int n, int sumnow){
	//visited[n] = true;
	if (sumnow >= dist[d] && n != d) return INF;
	if (sumnow == dist[d] && n == d){
		for (auto i : stk){
			ddd[i.first][i.second] = 1;
		}
	}
	for (auto i : adj[n]){
		stk.push_back(p(n, i.first));
		//if (!visited[i.first])
			dfs(i.first, sumnow + i.second);
		stk.pop_back();
	}
}

int main(){
	int n, m, s, i, a, b, c;
	while (1){
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;
		scanf("%d %d", &s, &d);
		for (i = 0; i < n; i++){
			adj[i].clear();
		}
		for (i = 0; i < m; i++){
			scanf("%d %d %d", &a, &b, &c);
			adj[a].push_back(p(b, c));
		}

		fill(dist, dist + Max_v, INF);

		fill(visited, visited + Max_v, 0);
		pq.push(p(0, s));
		dist[s] = 0;
		while (!pq.empty()){
			int curr;
			do{
				curr = pq.top().second;
				pq.pop();
			} while (!pq.empty() && visited[curr]);
			if (visited[curr]) break;

			visited[curr] = true;
			for (auto &P : adj[curr]){
				int next = P.first, dd = P.second;
				if (dist[next] > dist[curr] + dd){
					dist[next] = dist[curr] + dd;
				}
				pq.push(p(dist[next], next));
			}
		}
		if (dist[d] == INF) printf("%s", "INF");
		dfs(s, 0);

		fill(visited, visited + Max_v, 0);
		pq.push(p(0, s));
		fill(dist, dist + Max_v, INF);
		dist[s] = 0;
		while (!pq.empty()){
			int curr;
			do{
				curr = pq.top().second;
				pq.pop();
			} while (!pq.empty() && visited[curr]);
			if (visited[curr]) break;

			visited[curr] = true;
			for (auto &P : adj[curr]){
				int next = P.first, dd = P.second;
				if (ddd[curr][next] == 1) continue;
				if (dist[next] > dist[curr] + dd){
					dist[next] = dist[curr] + dd;
				}
				pq.push(p(dist[next], next));
			}
		}
		rslt.push_back(dist[d]);
	}
	for (i = 0; i < rslt.size(); i++)
		printf("%d\n", rslt[i] != INF ? rslt[i] : -1);
	return 0;

}
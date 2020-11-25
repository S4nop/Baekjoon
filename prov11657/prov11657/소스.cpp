#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#define INF 100000000
typedef std::pair<int, int> P;
using namespace std;
queue<int> q;
vector<P> city[505];
int dist[505];
int chk[505], visited[505];
int main(){
	ios_base::sync_with_stdio(false);
	int N, M, a, b, c;
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		cin >> a >> b >> c;
		city[a - 1].push_back(P(b - 1, c));
	}
	fill(dist, dist + 505, INF);
	chk[0] = 1;
	dist[0] = 0;
	q.push(0);
	while (!q.empty()){
		int n = q.front();
		q.pop();
		chk[n] = 0;
		if (++visited[n] >= N){
			cout << -1;
			return 0;
		}
		for (auto &v : city[n]){
			if (dist[v.first] > dist[n] + v.second){
				
				dist[v.first] = dist[n] + v.second;
				if (chk[v.first]) continue;
				chk[v.first] = 1;
				q.push(v.first);
			}
		}
	}

	for (int i = 1; i < N; i++)
		cout << (dist[i] == INF ? -1 : dist[i]) << endl;

	return 0;
}

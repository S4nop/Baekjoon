#include <cstdio>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <queue>
#define Max_e 30030
#define INF 2000000
using namespace std;

typedef pair <int, int> p;

vector<p> adj[Max_e];
int strt;
int main(){
	int v, e, a, b, c;
	scanf("%d %d %d", &v, &e, &strt);
	strt--;
	for (int i = 0; i < e; i++){
		scanf("%d %d %d", &a, &b, &c);
		adj[a - 1].push_back(p(b - 1, c));
	}
	priority_queue<p, vector<p>, greater<p>> pp;
	int dist[Max_e];
	bool visited[Max_e] = { 0 };
	fill(dist, dist + Max_e, INF);


	dist[strt] = 0;
	pp.push(p(0, strt));

	while (!pp.empty()){
		int tmp;
		do{
			tmp = pp.top().second;
			pp.pop();
		} while (!pp.empty() && visited[tmp]);
		if (visited[tmp]) break;;

		visited[tmp] = true;

		for (auto &t : adj[tmp]){
			if (dist[t.first] > dist[tmp] + t.second)
				dist[t.first] = dist[tmp] + t.second;
			pp.push(p(dist[t.first], t.first));
		}
	}

	for (int i = 0; i<v; i++){
		if (dist[i] == INF) puts("INF");
		else printf("%d\n", dist[i]);
	}
}

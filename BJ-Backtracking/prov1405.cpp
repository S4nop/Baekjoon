#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int N, map[30][30];
double e, w, s, n;

double DFS(int nx, int ny, int energy, double prob){
	if (map[ny][nx]) return 0;
	if (!energy) return prob;
	map[ny][nx] = 1;
	double ans = 0;
	ans += DFS(nx - 1, ny, energy - 1, prob * (w / 100));
	ans += DFS(nx + 1, ny, energy - 1, prob * (e / 100));
	ans += DFS(nx, ny - 1, energy - 1, prob * (s / 100));
	ans += DFS(nx, ny + 1, energy - 1, prob * (n / 100));
	map[ny][nx] = 0;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin >> N >> e >> w >> s >> n;

    cout << fixed;
    cout.precision(10);
	cout << DFS(15, 15, N, 1);
}
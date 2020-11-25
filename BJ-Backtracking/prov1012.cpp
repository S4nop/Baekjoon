#include <cstdio>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
int map[55][55];
bool chk[55][55];

void DFS(int x, int y){
	chk[x][y] = true;
	if (map[x - 1][y] && !chk[x - 1][y]) DFS(x - 1, y);
	if (map[x + 1][y] && !chk[x + 1][y]) DFS(x + 1, y);
	if (map[x][y - 1] && !chk[x][y - 1]) DFS(x, y - 1);
	if (map[x][y + 1] && !chk[x][y + 1]) DFS(x, y + 1);
}

int main(){
	ios_base::sync_with_stdio(0);
	int T, M, N, K, i, j, ta, tb, ans;
	cin >> T;
	while (T--){
		cin >> M >> N >> K;
		ans = 0;
		memset(map, 0, sizeof(int)* 55 * 55);
		memset(chk, 0, sizeof(bool)* 55 * 55);

		for (i = 0; i < K; i++){
			cin >> ta >> tb;
			map[ta + 1][tb + 1] = 1;
		}

		for (i = 1; i <= M; i++){
			for (j = 1; j <= N; j++){
				if (map[i][j] && !chk[i][j]){
					ans++;
					DFS(i, j);
				}
			}
		}

		cout << ans << "\n";
	}
	return 0;
}
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int R, C, map[22][22];

int DFS(int nx, int ny, int visited, int count){
	if (visited & (1 << (map[ny][nx] - 'A')) || !map[ny][nx]) return count;
	visited |= (1 << (map[ny][nx] - 'A'));

	int maxans = -1;
	maxans = max(DFS(nx - 1, ny, visited, count + 1), maxans);
	maxans = max(DFS(nx + 1, ny, visited, count + 1), maxans);
	maxans = max(DFS(nx, ny - 1, visited, count + 1), maxans);
	maxans = max(DFS(nx, ny + 1, visited, count + 1), maxans);

	return maxans;
}

int main(){
	int i, j;

	cin >> R >> C;
	for (i = 1; i <= R; i++){
		getchar();
		for (j = 1; j <= C; j++)
			map[i][j] = getchar();
	}
	printf("%d\n", DFS(1, 1, 0, 0));

    return 0;
}
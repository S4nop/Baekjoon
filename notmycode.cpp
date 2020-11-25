#include <stdio.h>
#pragma warning(disable:4996)

int adj[1100][1100] = { 0 };
int check[1100] = { 0 }; // check node visited in dfs
int check2[1100] = { 0 }; // check node visited in bfs (check 0 -> not visited, check 1 -> visited and not used for bfs, check 2 -> used for bfs
void dfs(int, int);
void bfs(int, int);

int main() {
	
	int nodeNum, edgeNum, start;

	scanf("%d %d %d", &nodeNum, &edgeNum, &start);
	for (int i = 0; i < edgeNum; i++) {
		int x, y;   
		scanf("%d %d", &x, &y);
		adj[x][y] = 1;
		adj[y][x] = 1;
	}

	dfs(start, nodeNum);
	
	check2[start] = 1; printf("\n%d ", start);
	bfs(start, nodeNum);
	
	return 0;
}

void dfs(int start, int size) {
	check[start]++;
	printf("%d ", start);
	
	for (int i = 1; i < size + 1; i++) {
		if (check[i] == 1)
			continue;
		if (adj[start][i] == 1) {
			dfs(i, size);
		}
	}
	return;
}

void bfs(int start, int size) {
	check2[start]++;
	
	for (int i = 1; i < size + 1; i++) {
		if (check2[i] != 0)
			continue;
		else if (adj[start][i] == 1) {
			printf("%d ", i);
			check2[i]++;
		}
	}

	for (int i = 1; i < size + 1; i++) {
		if (check2[i] != 2 && adj[start][i] == 1)
			bfs(i, size + 1);
	}

	return;
}
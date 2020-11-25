#include <cstdio>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int N, sticker[2][100100], dp[3][100100];

int DFS(int now, int prev){
	if (now == N) return 0;
	if (dp[prev][now] != -1) return dp[prev][now];
	int ans = -1;
	if (prev == 0){
		ans = max(ans, DFS(now + 1, 0));
		ans = max(ans, DFS(now + 1, 1) + sticker[0][now]);
		ans = max(ans, DFS(now + 1, 2) + sticker[1][now]);
	}
	else if (prev == 1){
		ans = max(ans, DFS(now + 1, 0));
		ans = max(ans, DFS(now + 1, 2) + sticker[1][now]);
	}
	else if (prev == 2){
		ans = max(ans, DFS(now + 1, 0));
		ans = max(ans, DFS(now + 1, 1) + sticker[0][now]);
	}

	return dp[prev][now] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	int T, i;
	cin >> T;

	while (T--){
		memset(dp, -1, sizeof(int)* 3 * 100100);
		cin >> N;
		for (i = 0; i < N; i++) cin >> sticker[0][i];
		for (i = 0; i < N; i++) cin >> sticker[1][i];

		cout << DFS(0, 0) << "\n";
	}
}
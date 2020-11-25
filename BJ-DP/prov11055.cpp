#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int N, A[1010], dp[1010];

int DFS(int now){
	if (dp[now] != -1) return dp[now];
	int i, ans = 0;
	for (i = now + 1; i < N; i++){
		if (A[i] > A[now]){
			ans = max(ans, DFS(i));
		}
	}
	return dp[now] = ans + A[now];
}

int main(){
	ios_base::sync_with_stdio(0);
	int i, ans = -1;
	cin >> N;
	for (i = 0; i < N; i++) cin >> A[i];
	memset(dp, -1, sizeof(int)* 1010);
	for (i = 0; i < N; i++) ans = max(ans, DFS(i));
	cout << ans;
}
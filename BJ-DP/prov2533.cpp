#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

vector<int> people[1000100];
int N, dp[1000100][2], visited[1000100];

int findEar(int now, int prev){
	if (dp[now][prev] != -1) return dp[now][prev];
	int i, ans = 0, tmpans = 0;
	visited[now] = 1;
	if (!prev){
		for (auto &v : people[now]){
			if (!visited[v]) ans += findEar(v, 1);
		}
		ans++;
	}
	else{
		for (auto &v : people[now]){
			if (!visited[v]) ans += findEar(v, 1);
		}
		ans++;
		for (auto &v : people[now]){
			if (!visited[v]) tmpans += findEar(v, 0);
		}
		ans = min(ans, tmpans);
	}
	visited[now] = 0;
	return dp[now][prev] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	int i, ta, tb;
	cin >> N;
	memset(dp, -1, sizeof(int)* 1000100 * 2);
	for (i = 0; i < N - 1; i++) {
		cin >> ta >> tb;
		people[ta - 1].push_back(tb - 1);
		people[tb - 1].push_back(ta - 1);	
	}

	cout << findEar(0, 1);

	return 0;
}
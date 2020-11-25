#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr;
int dp[100100][2];

int getCS(int n, int rem){
	if (dp[n][rem] != -1) return dp[n][rem];
	if (n == N - 1) return arr[n];
	int ans = -999999;
	if (!rem) ans = max(getCS(n + 1, 0) + arr[n], arr[n]);
	else ans = max(getCS(n + 1, 0), getCS(n + 1, 1) + arr[n]);
	return dp[n][rem] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	int tmp, sum = 0;
	cin >> N;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++){
		cin >> tmp;
		if (tmp < 0){
			arr.push_back(sum);
			sum = 0;
		}
		sum += tmp;
	}
	arr.push_back(tmp);
	N = arr.size();
	int ans = -999999999;
	for (int i = 0; i < N; i++)
		ans = max(ans, max(getCS(i, 1), getCS(i, 0)));
	cout << ans;
}
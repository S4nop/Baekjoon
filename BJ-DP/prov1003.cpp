#include <iostream>
#include <algorithm>

using namespace std;

long long dp[44];
int ans0, ans1;
long long fib(int n){
	if (dp[n] != -1) return dp[n];
	if (!n) { ans0++; return 1; }
	if (n == 1) { ans1++; return ((long long)1 << 32); }
	return dp[n] = fib(n - 1) + fib(n - 2);
}

int main(){
	ios_base::sync_with_stdio(0);
	int i, n, t; long long ans;

	cin >> t;
	while (t--){
		cin >> n;
		for (i = 0; i < 44; i++) dp[i] = -1;
		ans0 = 0; ans1 = 0;
		ans = fib(n);
		cout << (ans & 0xFFFFFFFF) << " " << (ans >> 32) << "\n";
	}
}
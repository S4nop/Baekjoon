#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

long long dp[110][10];
long long getStair(int num, int nowlen, int len){
	if (dp[nowlen][num] != -1) return dp[nowlen][num];
	if (nowlen == len) return 1;
	if (num == 9) return dp[nowlen][num] = getStair(8, nowlen + 1, len) % 1000000000;
	if (num == 0) return dp[nowlen][num] = getStair(1, nowlen + 1, len) % 1000000000;
	return dp[nowlen][num] = getStair(num - 1, nowlen + 1, len) % 1000000000 + getStair(num + 1, nowlen + 1, len) % 1000000000;
}


int main(){
	int n, i;
	long long ans = 0;
	cin >> n;
	memset(dp, -1, sizeof(long long)* 110 * 10);
	for (i = 1; i <= 9; i++)
		ans += (getStair(i, 1, n)) % 1000000000;

	cout << ans % 1000000000;
}
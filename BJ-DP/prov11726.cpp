#include <bits/stdc++.h>

#define ll long long
using namespace std;
long long dp[1010][1010];
long long cbdp[1010][1010];
ll comb(ll n, ll r){
	if (cbdp[n][r]) return cbdp[n][r];
	if (n == r || r == 0) return 1;
	if (r == 1) return n;
	cbdp[n][r] = (comb(n - 1, r - 1) + comb(n - 1, r)) % 10007;
	return cbdp[n][r];
}
ll getsp(ll o, ll t){
	if (dp[o][t]) return 0;
	dp[o][t] = comb(o + t, t);
	if (o >= 2) dp[o][t] += getsp(o - 2, t + 1);
	return dp[o][t];
}

int main(){
	ll t, n[150];
	cin >> t;
		printf("%lld\n", getsp(t, 0) % 10007);
		memset(dp, 0, sizeof(ll)* 1010 * 1010);
	
	return 0;

}
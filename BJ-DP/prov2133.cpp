#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, dp[33][33][33];

ll fillTile(ll n1, ll n2, ll n3){
    if(dp[n1][n2][n3]!= -1) return dp[n1][n2][n3];
    if(n1 == N && n2 == N && n3 == N) return 1;
    if(n1 > N || n2 > N || n3 > N) return 0;
    ll ans = 0;
    if(n1 == n2 && n2 == n3){
        ans += fillTile(n1 + 1, n2 + 1, n3 + 2);
        ans += fillTile(n1 + 2, n2 + 1, n3 + 1);
        ans += fillTile(n1 + 2, n2 + 2, n3 + 2);
    }
    else if(n1 < n2 && n2 == n3)
        ans += fillTile(n1 + 2, n2, n3);
    else if(n2 < n1 && n1 == n3)
        ans += fillTile(n1, n2 + 2, n3);
    else if(n3 < n1 && n1 == n2)
        ans += fillTile(n1, n2, n3 + 2);
    else if(n2 == n3 && n1 > n2){
        ans += fillTile(n1, n2 + 1, n3 + 1);
        ans += fillTile(n1, n2 + 2, n3 + 2);
    }
    else if(n2 == n1 && n3 > n2){
        ans += fillTile(n1 + 1, n2 + 1, n3);
        ans += fillTile(n1 + 2, n2 + 2, n3);
    }
    else if(n1 == n3 && n2 > n3){
        ans += fillTile(n1 + 2, n2, n3 + 2);
    }
    return dp[n1][n2][n3] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin >> N;
    ll ans = 0;
    memset(dp, -1, sizeof(dp));
    if(N == 1) cout << 0;
    else cout << fillTile(0, 0, 0);
    
}
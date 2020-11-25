#include <bits/stdc++.h>

using namespace std;

int N, arr[1010], dp[1010];

int getLDS(int n){
    if(dp[n] != -1) return dp[n];
    if(n == N - 1) return 1;
    int mx = -1;
    for(int i = n + 1; i < N; i++){
        if(arr[i] < arr[n])
            mx = max(mx, getLDS(i));
    }
    return dp[n] = mx == -1 ? 1 : mx + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    int ans = -1;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    for(int i = 0; i < N; i++)
        ans = max(ans, getLDS(i));
    cout << ans;
}
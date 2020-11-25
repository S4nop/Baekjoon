#include <bits/stdc++.h>

using namespace std;
int N, arr[1010], dp[1010][2];

int getLBS(int n, int ud){
    if(dp[n][ud] != -1) return dp[n][ud];
    if(n == N - 1) return 1;
    int mx = -1;
    for(int i = n + 1; i < N; i++)
        if(arr[i] < arr[n])
            mx = max(mx, getLBS(i, 1));

    if(!ud){
        for(int i = n + 1; i < N; i++)
            if(arr[i] > arr[n])
                mx = max(mx, getLBS(i, 0));
    }
    

    return dp[n][ud] = mx == -1 ? 1 : mx + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    int ans = -1;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    for(int i = 0; i < N; i++){
        ans = max(getLBS(i, 0), ans);
    } 
    cout << ans;


}
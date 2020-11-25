#include <iostream>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;

int val[10100];
int dp[10100];
int getMax(int n){
    if(dp[n] != -1) return dp[n];
    if(!n) return 1;
    int i, ans = -1;
    for(i = 1; i <= n; i++)
        ans = max(ans, getMax(n - val[i]) + val[i]);

    return dp[n] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    int N, i, ta;

    cin >> N;
    memset(dp, -1, sizeof(int) *10100);
    for(i = 1; i <= N; i++){
        cin >> val[i];
    }

    cout << getMax(N);
}
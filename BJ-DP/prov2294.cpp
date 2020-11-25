#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
int N, K, coin[110], dp[100100];

int DFS(int now, int cnt){
    if(now > K) return 999999;
    if(now == K) return cnt;
    if(dp[now] != -1) return dp[now];
    int ans = 999999, i;

    for(i = 0; i < N; i++)
        ans = min(ans, DFS(now + coin[i], cnt + 1));

    return dp[now] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    int i;
    cin >> N >> K;
    for(i = 0; i < N; i++) cin >> coin[i];

    sort(coin, coin + N);
    memset(dp, -1, sizeof(int) * 100100);
    i = DFS(0, 0);

    cout << ((i == 999999) ? -1 : i);


}
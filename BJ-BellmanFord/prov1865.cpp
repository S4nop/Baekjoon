#include <bits/stdc++.h>
#define INF 999999999
#define pair<int, int> pr
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, N, M, W, a, b, c, i, j, k, dist[505];

    cin >> T;
    while(T--){
        fill(dist, dist + 505, INF);
        vector<pr> adj[505];
        cin >> N >> M >> W;
        for(i = 0; i < M; i++){
            cin >> a >> b >> c;
            adj[a - 1].push_back(pr(b - 1, c));
        }
        for(i = 0; i < W; i++){
            cin >> a >> b >> c;
            adj[a - 1].push_back(pr(b - 1, -1*c));
        }

        for(i = 0; i < N; i++){
            for(j = )
        }
    }

}
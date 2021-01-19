#include <bits/stdc++.h>

using namespace std;

int censor[10010];
int dist[10010];

int main(){
    ios_base::sync_with_stdio(0);
    int N, K;
    long long ans = 0;

    cin >> N >> K;

    for(int i = 0; i < N; i++)
        cin >> censor[i];

    sort(censor, censor+N, greater<int>());

    for(int i = 0; i < N - 1; i++){
        dist[i] = censor[i] - censor[i + 1];
        ans += dist[i];
    }

    for(int i = 1; i < K; i++){
        int mx = -1, cut_point = -1;
        for(int j = 0; j < N - 1; j++){
            if(dist[j] > mx){
                mx = dist[j];
                cut_point = j;
            }
        }
        if(cut_point != -1){
            ans -= dist[cut_point];
            dist[cut_point] = 0;

        }
    }

    cout << ans;
    
    
}
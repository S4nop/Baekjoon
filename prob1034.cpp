#include <bits/stdc++.h>

using namespace std;
int N, M, K;



int main(){
    ios_base::sync_with_stdio(0);
    char tb[55][55];
    int mx = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        tb[i][M+4] = 0;
        for(int j = 0; j < M; j++){
            cin >> tb[i][j];
            if(tb[i][j] == '0')
                ++tb[i][M + 4];
        }
    }
    cin >> K; 

    for(int i = 0; i < N; i++){
        int cnt = 0;
        if(tb[i][M + 4] <= K && tb[i][M + 4] % 2 == K % 2){
            for(int j = 0; j < N; j++){
                if(!strcmp(tb[i], tb[j])) ++cnt;
            }
        }
        mx = max(cnt, mx);
    }
    cout << mx;
}
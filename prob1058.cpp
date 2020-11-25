#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int N, frnd[55][55], ans = -1;
    char inp;
    memset(frnd, 0, sizeof(frnd));

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> inp;
            if(i == j) continue;
            if(inp == 'Y') frnd[j][i] = frnd[i][j] = 1;
        }
    }

    for(int i = 0; i < N; i++){
        int two_friends = 0;
        for(int j = 0; j < N; j++){
            if(frnd[i][j] == 1){
                ++two_friends;
                for(int k = 0; k < N; k++){
                    if(i != k && frnd[j][k] == 1 && !frnd[i][k]){
                        frnd[i][k] = 2;
                        two_friends++;
                    }
                }
            }
        }
        ans = max(ans, two_friends);
    }
    cout << ans << "\n";
}
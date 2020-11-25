#include <bits/stdc++.h>

using namespace std;
int sw[55][55];
int partialSum[55][55];

int main(){
    ios_base::sync_with_stdio(0);
    int n, m, x = 1, rslt = 9999999;
    char c;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        x = 1 * (int)pow(-1, i);
        for(int j = 0; j < m; j++){
            cin >> c;
            if(!(c == 'W' && x == -1) && !(c == 'B' && x == 1)){
               sw[i][j] = 1; 
            }
            x *= -1;
        }
    }
    for(int i = 0; i < n; i++){
        int s = 0;
        for(int j = 0; j < m; j++){
            s += sw[i][j];
            partialSum[i + 1][j + 1] = s;
        }
    }
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            partialSum[i + 1][j + 1] += partialSum[i][j + 1];
        }
    }
    for(int i = 0; i < n - 7; i++){
        for(int j = 0; j < m - 7; j++){
            int tmp = partialSum[i+8][j+8] - partialSum[i + 8][j] - partialSum[i][j+8] + partialSum[i][j];
            rslt = min(rslt, min(tmp, abs(64 - tmp)));
        }
    }
    cout << rslt;
}
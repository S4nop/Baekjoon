#include <bits/stdc++.h>

using namespace std;
char dp[220][10];

int recur(char* inp, int idx, int cs){
    if(dp[idx][cs] != -1) return dp[idx][cs]; 
    int rec;

    if(cs == 0){
        if(inp[idx] == 0) return 1;
        if(inp[idx] == '1' && recur(inp, idx + 1, 1)) return dp[idx][cs] = 1;
        if(inp[idx] == '0' && recur(inp, idx + 1, 4)) return dp[idx][cs] = 1;
        return dp[idx][cs] = 0;
    }

    if(cs == 1){
        if(inp[idx] == '0' && recur(inp, idx + 1, 2)) return dp[idx][cs] = 1;
        return dp[idx][cs] = 0;
    } 

    if(cs == 2){
        if(inp[idx] == '0' && (recur(inp, idx + 1, 2) || recur(inp, idx + 1, 3))) return dp[idx][cs] = 1;
        return dp[idx][cs] = 0;
    }

    if(cs == 3){
        if(inp[idx] == '1' && (recur(inp, idx + 1, 3) || recur(inp, idx + 1, 0))) return dp[idx][cs] = 1;
        return dp[idx][cs] = 0;
    }

    if(cs == 4){
        if(inp[idx] == '1' && recur(inp, idx + 1, 0)) return dp[idx][cs] = 1;
        return dp[idx][cs] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; 
    char inp[220];
    char* pInp = inp;
    cin >> T;
    while(T--){
        cin >> inp;
        memset(dp, -1, sizeof(dp));
        cout << (recur(inp, 0, 0) ? "YES" : "NO") << "\n";
    }
}
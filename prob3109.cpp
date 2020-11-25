#include <bits/stdc++.h>

using namespace std;
int rt[10010][505];
int R, C;

int goRoute(int r, int c){
    rt[r][c] = 0;
    if(c == C) return 1;
    int ans;

    if(rt[r-1][c+1] && (ans = goRoute(r-1, c+1))) return ans;
    if(rt[r][c+1] && (ans = goRoute(r, c+1))) return ans;
    if(rt[r+1][c+1] && (ans = goRoute(r+1, c+1))) return ans;
    return 0;
}

void showMap(){
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cout << rt[i][j];
        }
        cout << "\n";
    }

}


int main(){
    ios_base::sync_with_stdio(0);
    char tmp;
    int ans = 0;
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> tmp;
            rt[i][j] = (tmp == '.');
        }
    }

    for(int r = 1; r <= R; r++){
        if(rt[r][1]) ans += goRoute(r, 1);
    }

    cout << ans;
}
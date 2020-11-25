#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int T, x1, y1, x2, y2, r1, r2;
    cin >> T;
    while(T--){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if(x1 == x2 && y1 == y2){
            if(r1 == r2) cout << -1 << "\n";
            else cout << 0 << "\n";
            continue;
        }
        double r = pow(x1 - x2, 2) + pow(y1 - y2, 2);
        double rn = pow(r1 + r2, 2);
        if(r == rn) cout << 1 << "\n";
        else if(r < rn){
            if(r == pow(r1 - r2, 2)) cout << 1 << "\n";
            else if(r < pow(r1 - r2, 2)) cout << 0 << "\n";
            else cout << 2 << "\n";
        }
        else cout << 0 << "\n";
    }
}
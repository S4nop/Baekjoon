#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int T, x1, y1, x2, y2, oNum, o_x, o_y, o_r, ans = 0;
    cin >> T;
    while(T--){
        ans = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> oNum;
        while(oNum--){
            cin >> o_x >> o_y >> o_r;
            ans += ((pow(o_x - x1, 2) + pow(o_y - y1, 2) < pow(o_r, 2)) ^ (pow(o_x - x2, 2) + pow(o_y - y2, 2) < pow(o_r, 2)));
        }
        cout << ans << "\n";
    }
}
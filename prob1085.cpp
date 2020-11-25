#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    cout << min(x, min(y, min(w - x, h - y)));
}
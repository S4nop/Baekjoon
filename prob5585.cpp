#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int n, ans = 0;
    cin >> n;
    n = 1000 - n;

    while(n >= 500 && ++ans) n -= 500;
    while(n >= 100 && ++ans) n -= 100;
    while(n >= 50 && ++ans) n -= 50;
    while(n >= 10 && ++ans) n -= 10;
    while(n >= 5 && ++ans) n -= 5;
    cout << ans + n;
}
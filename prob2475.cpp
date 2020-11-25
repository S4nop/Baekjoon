#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int n[5];
    for(int i = 0; i < 5; i++)
        cin >> n[i];
    
    cout << (n[0]*n[0] + n[1]*n[1] + n[2]*n[2] + n[3]*n[3] + n[4]*n[4]) % 10;
}
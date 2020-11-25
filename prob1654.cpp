#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll line[10100];


int main(){
    ios_base::sync_with_stdio(0);
    ll k, n, ans;
    ll sum = 0, mn = 99999999;
    cin >> k >> n;
    for(int i = 0; i < k; i++){
        cin >> line[i];
        sum += line[i];
        mn = min(mn, line[i]);
    }
    ans = sum / n;



    cout << sum;

}
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    vector<int> titles;
    int n, x = 0;
    cin >> n;
    for(x = 0; x < 10000; x++){
        titles.push_back(x *= 1000 + 666);
        titles.push_back((x / 10) * 10000 + 6660);
        titles.push_back((x / 100) * 100000 + 66600);
        titles.push_back((x / 1000) * 1000000 + 666000);
    }
    sort(titles.begin(), titles.end(), greater<int>());
    cout << titles[n + 1];
}
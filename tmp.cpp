#include <bits/stdc++.h>

using namespace std;

void makeStr(int a){
    if(!a) return;
    char tmp[100000000];
    cout << "-" << a;
    makeStr(a - strlen(itoa(a, tmp, 10) - 1));
}

int main(){
    ios_base::sync_with_stdio(0);
    int a;
    while(1){
        cin >> a;
        if(!a) break;
        makeStr(a);
    }
}
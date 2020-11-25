#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll N, num[6];
ll mn[3] = {999, 999, 999};

void setDice(){
    int i, min_i;
    for(i = 0; i < 6; i++)
        if(mn[0] > num[i]) {
            min_i = i;
            mn[0] = num[i];
        }
    num[min_i] = num[5 - min_i] = 9999;
    for(i = 0; i < 6; i++)
        if(mn[1] > num[i]) {
            min_i = i;
            mn[1] = num[i];
        }
    num[min_i] = num[5 - min_i] = 9999;
    for(i = 0; i < 6; i++)
        if(mn[2] > num[i]) {
            min_i = i;
            mn[2] = num[i];
        }
    num[min_i] = num[5 - min_i] = 9999;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin >> N;
    for(int i = 0; i < 6; i++) cin >> num[i];
    if(N == 1){
        ll sm = 0, mx = -1;
        for(int i = 0; i < 6; i++){
            sm += num[i];
            mx = max(mx, num[i]);
        }
        cout << sm - mx;
    }
    else{
        setDice();
        cout << (N > 2 ? ((2*N*N+2*N*(N-2)+(N-2)*(N-2))*mn[0]+(4*N+4*(N-2))*mn[1]+4*mn[2]) : 8*mn[0]+8*mn[1]+4*mn[2]);
    }
}
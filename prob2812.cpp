#include <bits/stdc++.h>

using namespace std;
int num[500500];
bool erased[500500];
int N, K;

int main(){
    ios_base::sync_with_stdio(0);
    char tmp;
    int i;
    cin >> N >> K;
    fill(num, num+500000, 9999);
    for(i = 0; i < N; i++){
        cin >> tmp;
        num[i] = tmp - '0';
    }

    int cnt = 0;
    while(K){
        int mx = -1;
        for(i = cnt; i < K + cnt + 1; i++){
            mx = max(mx, num[i]);
            if(mx == 9) break;
        }

        if(num[i = cnt] == mx){
            ++cnt;
            continue;
        }

        while(num[i] < mx){
            erased[i++] = true;
            --K;
            ++cnt;
        }
    }
    
    for(i = 0; i < N; i++){
        if(!erased[i]){
            if(K){
                --K;
                continue;
            }
            cout << num[i];
        } 
    }

}
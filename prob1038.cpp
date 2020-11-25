#include <bits/stdc++.h>

using namespace std;
int dp[1000100];
queue<int> q1, q2;

int getAns(int num){

}

int main(){
    ios_base::sync_with_stdio(0);
    int N, x = 0;
    char ans[11];
    for(int i = 0; i < 10; i++){
        dp[i] = 1;
        q1.push(i);
    }

    while(1){
        while(!q1.empty()){
            int q = q1.front();
            q1.pop();
            for(int i = 0; i < q % 10; i++){
                
            }
        }
    }

}
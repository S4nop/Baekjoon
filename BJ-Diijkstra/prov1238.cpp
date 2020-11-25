#include <bits/stdc++.h>

using namespace std;

int mMap[110][110];
vector<pair<int, int>> road[1010];
int fromHere[1010], tmpHere[1010];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int M, N, X, i, j, tu, tv, tw;
    cin >> N >> M >> X;
    cin.ignore();
    
    for(i = 0; i < M; i++){
        cin >> tu >> tv >> tw;
        road[tu].push_back(make_pair(tw, tv));
    }

    for(i = 0; i < N; i++)
        sort(road[i].begin(), road[i].end());
    

    for(i = 0; i < N; i++){
        memset(tmpHere, 0, sizeof(memset));
        priority_queue<int, vector<int>, greater<int>> tmpQ;
        for(auto &v : road[i]){
            tmpQ.push(i);
            while(!tmpQ.empty()){
                tu = tmpQ.top();
                tmpQ.pop();
                if(tu == X){
                    fromHere[i] = tmpHere[X];
                    break;
                }
                for(auto &u : road[tu]){
                    if(tmpHere[u.second] > tmpHere[tu] + u.first){
                        tmpHere[u.second] = tmpHere[tu] + u.first;
                        tmpQ.push(u.second);
                    }
                }
            }
        }
    }
    
    memset(tmpHere, 0, sizeof(memset));
    priority_queue<int, vector<int>, greater<int>> tmpQ;
    tmpQ.push(X);

    while(!tmpQ.empty()){
        tu = tmpQ.top();
        tmpQ.pop();
        for(auto &u : road[tu]){
            if(tmpHere[u.second] > tmpHere[tu] + u.first){
                tmpHere[u.second] = tmpHere[tu] + u.first;
                tmpQ.push(u.second);
            }
        }
    }
        
    for(i = 0; i < N; i++)
        fromHere[i] += tmpHere[i];
    
    sort(fromHere, fromHere + N, greater<int>());

    cout << fromHere[0];


}
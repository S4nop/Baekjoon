#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> network[1010];
int minSpeed[1010];
bool netOn[1010][1010]
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, i, tu, tv, tw;
    for(i = 0; i < M; i++){
        cin >> tu >> tv >> tw;
        network[tu].push_back(make_pair(tw, tv - 1));
        network[tv].push_back(make_pair(tw, tu - 1));
    }

    queue<int> q;
    q.push(0);
    memset(minSpeed, 99999999, sizeof(minSpeed));
    for(i = 0; i < N; i++)
        sort(network[i].begin(), network[i].end(), greater<pair<int, int>>());
    while(!q.empty()){
        ut = q.front();
        q.pop();
        for(auto &v : network[ut]){
            if(minSpeed[v.second] > minSpeed[ut] + v.first){
                memset(netOn[v.second], 0, sizeof(netOn[v.second]));
                netOn[v.second][ut] = true;
                
            }
        }
    }

}
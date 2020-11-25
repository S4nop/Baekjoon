#include <cstdio>                                                                                       
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int indeg[505], rtime[505], rslt[505];
int main(){
    ios_base::sync_with_stdio(0);
    int n, i, tmp;
    queue<int> Q;
    vector<int> adj[505];
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> rtime[i];
        while(1){
            cin >> tmp;
            if(tmp == -1) break;
            adj[tmp - 1].push_back(i);
            indeg[i]++; 
        }
     
        if(indeg[i] == 0) {
            Q.push(i);
            rslt[i] = rtime[i];
        }
    }   

    for(i = 0; i < n; i++){
        int curr = Q.front();
        Q.pop();

        for(int n : adj[curr]){
            rslt[n] = max(rslt[n], rtime[n] + rslt[curr]);
            if(--indeg[n] == 0) Q.push(n); 
        }
    }   

    for(i = 0; i < n; i++)
        cout << rslt[i] << endl;

    return 0;
}

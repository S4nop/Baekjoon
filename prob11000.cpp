#include <bits/stdc++.h>

using namespace std;
pair<int, int> cls[200200];
int tt[200200];
set<int> stt[200200];
queue<int> ed[200200];
int main(){
    ios_base::sync_with_stdio(0);
    int N, s, t, ans = 1, mx = -1;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s >> t;
        mx = max(s, mx);
        if(!ed[s].empty()){
            int st = ed[s].front();
            ed[s].pop();
            stt[st].erase(s);
            stt[st].insert(t); 
            ed[t].push(st);
        } 
        else{
            stt[s].insert(t);
            ed[t].push(s);
        }
    }

    for(int i = 1; i <= mx; i++){
        if(stt[i].empty()) continue;
        int pos = 1;
        for(set<int>::iterator it = stt[i].begin(); it != stt[i].end(); it++){
            while(tt[pos] > *it) ++pos;
            tt[pos] = *it;
            if(ans < pos) ans = pos;
        }
    }

    cout << ans;
}
#include <bits/stdc++.h>

using namespace std;
int G, P;
set<int> g;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> G >> P;
    int tmp, ans = 0;

    for(int i = 0; i <= G; i++){
        g.insert(i);
    }
    for(int i = 0; i < P; i++){
        cin >> tmp;
        set<int>::iterator it = g.lower_bound(tmp);
        
        if(it != g.end() && *it == tmp) g.erase(it);
        else if(--it == g.begin()) break;
        else g.erase(it);
        ++ans;
        if(g.size() == 1) break;
    }

    cout << "\n" << ans;
}
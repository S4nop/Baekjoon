#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <utility>
using namespace std;

queue<pair<int, int>> q;
set<int> ms;
pair<int, int> nowme;
int main(){
    ios_base::sync_with_stdio(0);
    int f, s, g, u, d, ta, tb;
    cin >> f >> s >> g >> u >> d;

    nowme.first = s;
    nowme.second = 0;

    q.push(nowme);
    ms.insert(s);

    while(!q.empty()){
        ta = q.top().first;
        tb = q.top().second;
        if(ta == g){
            cout << tb;
            return 0;
        }

        if(ta - d > 0 && ms.find(ta - d)){
            nowme.first = ta - d;
            nowme.second = tb + 1;
            q.push_back(nowme);
            s.insert(ta - d);
        }
        if(ta + u < f && ms.find(ta + u)){
            nowme.first = ta + u;
            nowme.second = tb + 1;
            q.push_back(nowme);
            s.insert(ta + u);
        }
        tb++;
        
    }

}
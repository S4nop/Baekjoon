#include <bits/stdc++.h>

using namespace std;

multiset<int> s;

int main(){
    ios_base::sync_with_stdio(0);
    char now[10], l_finder[10], u_finder[10];
    char* nPtr = now;
    int n, tmp, now_num, len;
    cin >> now >> n;
    for(int i = 0; i < 10; i++) s.insert(i);
    for(int i = 0; i < n; i++){
        cin >> tmp;
        s.erase(tmp);
    }

    now_num = atoi(now);
    len = strlen(now);
    
    for(int i = 0; i < n; i++){
        if(s.find(now[i] - '0') != s.end()) ++nPtr;
    }

    if(*nPtr){
        auto iter = s.upper_bound(*nPtr - '0');
        if(iter != s.end())
            u_finder[0] = *iter + '0';
        
        iter = s.lower_bound(*nPtr - '0');
        if(iter != s.begin())
            l_finder[0] = *--iter + '0';
    }
}
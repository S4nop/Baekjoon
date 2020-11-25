#include <bits/stdc++.h>

using namespace std;

set<int> multitap;
vector<int> order;
int N, K, nm, for_used, used[110];

void makeUsed(){
    
}

int main(){
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i < K; i++){
        cin >> nm;
        order.emplace_back(nm);
    }

    for(int i = 0; i < K; i++){
        if(multitap.find(order[i]) != multitap.end()) continue;
        if(multitap.size() <= 8) {
            multitap.insert(order[i]);
            continue;
        }

    }

}
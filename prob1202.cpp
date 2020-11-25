#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int N, K, mi, vi, ci;
    long long sum = 0;
    vector<pair<int, int>> jewels;
    multiset<int> bags;

    cin >> N >> K;

    for(int i = 0; i < N; i++){
        cin >> mi >> vi;
        jewels.emplace_back(make_pair(vi, mi));
    }

    for(int i = 0; i < K; i++){
        cin >> ci;
        bags.insert(ci);
    }

    sort(jewels.begin(), jewels.end(), greater<pair<int, int>>());

    for(auto jew : jewels){
        if(bags.empty()) break;
        multiset<int>::iterator it = bags.lower_bound(jew.second);
        if(it == bags.end()) continue;
        sum += jew.first;
        bags.erase(it);
    }

    cout << sum;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    vector<int> weight;
    int N, tmp, sum = 0;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> tmp;
        weight.emplace_back(tmp);
    }

    sort(weight.begin(), weight.end());

    for(auto n : weight){
        if(n > sum+1) break;
        sum += n;
    }

    cout << sum + 1;

}
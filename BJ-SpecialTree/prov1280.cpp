#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int N, tnum[202000]; ll x[202000], fwtree[202000];

void update(int i){
    while(i <= N){
        fwtree[i] += 1;
        i += (i & -i);
    }
}
ll sum(int i){
    ll ans = 0;
    while(i > 0){
        ans += fwtree[i];
        i -= (i & -i);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    int i, j; ll ans = 1;
    cin >> N;
    cin >> x[1];
    update(x[1] + 1);
    for(i = 2; i <= N; i++){
        cin >> x[i];
        if(!fwtree[++x[i]]) update(x[i]);
        for(j = 1; j < i; j++){
            ans += x[i] >= x[j] ? sum(x[i]) - sum(x[j] - 1) : sum(x[j]) - sum(x[i] - 1);
            ans %= 1000000007;
        }
    }

    cout << ans;
}
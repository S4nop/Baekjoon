#include <cstdio>
#define ll long long
using namespace std;
int N, Q;
ll num[101000];
ll fwtree[201000];

void update(ll num, int i){
	while (i <= N + 1){
		fwtree[i] += num;
		i += (i & -i);
	}
}

ll sum(int i){
	ll ans = 0;
	while (i > 0){
		ans += fwtree[i];
		i -= (i & -i);
	}
	return ans;
}

int main(){
	int i, j, a, b, c; ll d;
    scanf("%d %d", &N, &Q);
	for (i = 1; i <= N; i++){
        scanf("%lld", &num[i]);
		update(num[i], i);
	}

	for (i = 0; i < Q; i++){
        scanf("%d %d %d %lld", &a, &b, &c, &d);
        printf("%lld\n", b >= a ? sum(b) - sum(a - 1) : sum(a) - sum(b - 1));
		update(d - num[c], c);
        num[c] = d;
	}

	return 0;
}
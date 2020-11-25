#include <iostream>
#include <algorithm>

#define ll long long
using namespace std;
ll N, M, K;
ll nd[4000000] = { 0, };

void update(int start, int end, int now, int tochange, ll diff){
	if (tochange < start || tochange > end) return;
	nd[now] += diff;
	if (start == end) return;
	int mid = (start + end) % 2 ? (start + end) / 2 : (start + end) / 2 + 1;
	if (tochange > mid) update(mid + 1, end, now * 2 + 1, tochange, diff);
	else update(start, mid, now * 2, tochange, diff);
}

ll sum(int start, int end, int dstart, int dend, int now){
	if (start > dend || end < dstart) return 0;
	if (start >= dstart && end <= dend) return nd[now];
	int mid = (start + end) / 2;
	return sum(mid + 1, end, dstart, dend, now * 2 + 1) + sum(start, mid, dstart, dend, now * 2);
}
int main(){
	ios_base::sync_with_stdio(0);
	int i, j, nowidx = 0, orgidx = 0, newN, a, b;
	ll tmp, c;
	cin >> N >> M >> K;

	for (i = 1; i < N; i *= 2){
		orgidx += i;
	}
	newN = i;
	nowidx = orgidx;
	for (i = 0; i < N; i++){
		cin >> tmp;
		for (j = ++nowidx; j > 0; j = j % 2 ? (j - 1) / 2 : j / 2){
			nd[j] += tmp;
		}
	}

	for (i = 0; i < M + K; i++){
		cin >> a >> b >> c;
		if (a == 1) update(1, newN, 1, b, c - nd[orgidx + b]);
		else cout << sum(1, newN, b, c, 1) << "\n";
	}
}
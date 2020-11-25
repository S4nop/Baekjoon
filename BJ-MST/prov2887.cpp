#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef tuple<int, int, int, int> Edge;
typedef tuple<ll, int, int> road;
int uf[100100];

int find_union(int n){
	if (uf[n] == -1) return n;
	else return uf[n] = find_union(uf[n]);
}

bool make_union(int a, int b){
	int ua = find_union(a);
	int ub = find_union(b);
	if (ua == ub) return false;
	uf[ua] = ub;
	return true;
}

priority_queue<road, vector<road>, greater<road>> tunnel;
Edge planet[100100];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, i, tx, ty, tz, ans = 0;
	cin >> N;
	ll rslt = 0;
	memset(uf, -1, sizeof(uf));
	for (i = 0; i < N; i++){
		cin >> tx >> ty >> tz;
		planet[i] = Edge(tx, ty, tz, i);
	}
	
	sort(planet, planet + N);
	for (i = 0; i < N - 1; i++){
		tunnel.push(make_tuple(abs(get<0>(planet[i + 1]) - get<0>(planet[i])), get<3>(planet[i]), get<3>(planet[i + 1])));
	}

	sort(planet, planet + N, [](Edge a, Edge b){ return get<1>(a) < get<1>(b); });
	for (i = 0; i < N - 1; i++){
		tunnel.push(make_tuple(abs(get<1>(planet[i + 1]) - get<1>(planet[i])), get<3>(planet[i]), get<3>(planet[i + 1])));
	}

	sort(planet, planet + N, [](Edge a, Edge b){ return get<2>(a) < get<2>(b); });
	for (i = 0; i < N - 1; i++){
		tunnel.push(make_tuple(abs(get<2>(planet[i + 1]) - get<2>(planet[i])), get<3>(planet[i]), get<3>(planet[i + 1])));
	}
	ll dist; int a, b;
	while (ans != N - 1){
		tie(dist, a, b) = tunnel.top();
		tunnel.pop();
		if (make_union(a, b)){
			ans++;
			rslt += dist;
		}
	}

	cout << rslt;
}
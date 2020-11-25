#include <bits/stdc++.h>
using namespace std;

int uf[1010];

inline double getDist(int ax, int ay, int bx, int by) { return sqrt(1LL*(ax - bx)*(ax - bx) + 1LL*(ay - by)*(ay - by)); }

struct conLine{
	int u, v;
	double w;
	conLine(int a, int b, double c) : u(a), v(b), w(c) {}
	conLine() : conLine(-1, -1, 0) {}
	bool operator <(const conLine &a)const{ return w > a.w; }
};

struct node{
	int x, y, r;
	node(int a, int b, int c) : x(a), y(b), r(c) {}
	node() : node(-1, -1, 0) {}
} nd[1010];

int find_union(int n){
	if (uf[n] == -1) return n;
	return find_union(uf[n]);
}

bool make_union(int ta, int tb){
	int a = find_union(ta);
	int b = find_union(tb);
	if (a == b) return false;
	uf[a] = b;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(6);
	int T, W, N, tx, ty, tr, i, j;
	double rslt;
	cin >> T;
	while (T--){
		cin >> W >> N;
		priority_queue<conLine> l;
		l.push(conLine(N, N + 1, W));
		memset(uf, -1, sizeof(uf));
		for (i = 0; i < N; i++){
			cin >> tx >> ty >> tr;
			l.push(conLine(N, i, max(0, W - tx - tr)));
			l.push(conLine(N + 1, i, max(0, tx - tr)));
			nd[i] = node(tx, ty, tr);
			for (j = 0; j < i; j++){
				double tmp = getDist(tx, ty, nd[j].x, nd[j].y);
				rslt = max(getDist(tx, ty, nd[j].x, nd[j].y) - tr - nd[j].r, (double)0);
				l.push(conLine(j, i, rslt));

			}
		}

			while (!l.empty() && find_union(N) != find_union(N + 1) && find_union(N) != -1 && find_union(N) != -1){
			make_union(l.top().u, l.top().v);
			rslt = l.top().w;
			l.pop();
		}
		cout << (rslt > 0 ? rslt / 2 : 0) << "\n";
	}

}
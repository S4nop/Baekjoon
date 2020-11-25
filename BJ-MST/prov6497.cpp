#include <bits/stdc++.h>
using namespace std;

int uni[200200];

struct Edge{
	int u, v, w;
	Edge(int tu, int tv, int tw) : u(tu), v(tv), w(tw){}
	Edge() : Edge(-1, -1, 0){}
} H[200200];

int make_union(int n){
	if (uni[n] == -1) return n;
	return uni[n] = make_union(uni[n]);
}

bool find_union(int a, int b){
	int ma = make_union(a);
	int mb = make_union(b);
	if (ma == mb) return false;
	uni[ma] = mb;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M, i, ta, tb, tc, Anssum, numConnected;
    while(1){
        cin >> M >> N;
        if(M == 0 && N == 0) break;
        memset(uni, -1, sizeof(uni));
        Anssum = 0, numConnected = 0;
        for (i = 0; i < N; i++){
            cin >> ta >> tb >> tc;
            H[i] = Edge(ta, tb, tc);
            uni[ta] = -1;
            Anssum += tc;
        }

        sort(H, H + N, [](Edge a, Edge b){return a.w < b.w; });
        for (i = 0; i < N; i++){
            if (find_union(H[i].v, H[i].u)){
                Anssum -= H[i].w;
                if (++numConnected == M) break;
            }
        }

        cout << Anssum << "\n";
    }
}


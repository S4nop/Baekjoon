#include <bits/stdc++.h>
using namespace std;
int bTime[1010];
struct node{
	vector<int> next;
	int need;
	node() { need = 0; }
};
int main(){
	int T, N, K, W, ta, tb, i, mxbTime[1010];
	cin >> T;
	while (T--){
		cin >> N >> K;
		memset(mxbTime, 0, sizeof(mxbTime));
		node build[1010];
		for (i = 0; i < N; i++)
			cin >> bTime[i];

		for (i = 0; i < K; i++){
			cin >> ta >> tb;
			build[ta - 1].next.push_back(tb - 1);
			build[tb - 1].need++;
		}

		cin >> W;

		queue<int> q;

		for (i = 0; i < N; i++){
			sort(build[i].next.begin(), build[i].next.end(), [](int a, int b){return bTime[a] < bTime[b]; });
			if (!build[i].need) {
				q.push(i);
				mxbTime[i] = bTime[i];
			}
		}

		while (!q.empty()){
			ta = q.front();
			if (ta == W - 1) break;
			q.pop();

			for (auto &v : build[ta].next){
				if(--build[v].need <= 0) q.push(v);
				if (mxbTime[v] < bTime[v] + mxbTime[ta]) mxbTime[v] = bTime[v] + mxbTime[ta];
			}
		}

		cout << mxbTime[W - 1] << "\n";
	}
}
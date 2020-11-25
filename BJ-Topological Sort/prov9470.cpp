#include <bits/stdc++.h>

using namespace std;
struct riv{
	vector<int> next;
	int toMe;
	int strahler;
	int mx;
	riv(){ toMe = 0; strahler = 0; mx = -1; }
} river[1010];

queue<int> q;
int main(){
	ios_base::sync_with_stdio(0);
	int T, t, K, M, P, i, ta, tb;
	cin >> T;
	for (t = 1; t <= T; t++){
		cin >> K >> M >> P;
		riv river[1010];
		for (i = 0; i < P; i++){
			cin >> ta >> tb;
			river[ta - 1].next.push_back(tb - 1);
			river[tb - 1].toMe++;
		}
		for (i = 0; i < M; i++){
			if (!river[i].toMe) q.push(i);
		}

		while (!q.empty()){
			ta = q.front();
			q.pop();
			for (auto &v : river[ta].next){
				if (river[v].mx == river[ta].strahler){
					river[v].strahler = river[ta].strahler + 1;
				}
				else if (river[v].mx < river[ta].strahler){
					river[v].strahler = river[ta].strahler;
					river[v].mx = river[ta].strahler;
				}
				if(--river[v].toMe <= 0) q.push(v);
			}
		}
		cout << t << " " << river[M - 1].strahler + 1<< "\n";
	}


	
}
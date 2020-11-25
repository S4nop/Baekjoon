#include <bits/stdc++.h>

using namespace std;
int N, M;
struct problem{
	vector<int> next;
	int prev = 0;
	bool solved = 0;
} prov[32320];
queue<int> ans;
priority_queue<int, vector<int>, greater<int>> pq;


int main(){
	ios_base::sync_with_stdio(0);
	int i, tmpa, tmpb;
	cin >> N >> M;
	for (i = 0; i < M; i++){
		cin >> tmpa >> tmpb;
		prov[tmpa].next.push_back(tmpb);
		prov[tmpb].prev++;
	}
	for (i = 1; i <= N; i++)
	if (!prov[i].prev) pq.push(i);

	while (!pq.empty()){
		int n = pq.top();
		pq.pop();
		ans.push(n);
		for (auto &v : prov[n].next){
			if (!prov[v].solved && --prov[v].prev == 0) pq.push(v);
		}
	}

	while (!ans.empty()){
		cout << ans.front() << " ";
		ans.pop();
	}
}
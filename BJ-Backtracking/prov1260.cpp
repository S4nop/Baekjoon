#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct node{
	int connected[10100];
	int cnum;
	bool bfschk;
	bool dfschk;
	node(){ cnum = 0; bfschk = false; dfschk = false; }
} nd[1010];

queue<int> q;

void DFS(int now){
	int i;
	cout << now << " ";
	nd[now].dfschk = true;
	for (i = 0; i < nd[now].cnum; i++){
		if (!nd[nd[now].connected[i]].dfschk)
			DFS(nd[now].connected[i]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	int N, M, V, i, ta, tb;
	cin >> N >> M >> V;

	for (i = 0; i < M; i++){
		cin >> ta >> tb;
		nd[ta].connected[nd[ta].cnum++] = tb;
		nd[tb].connected[nd[tb].cnum++] = ta;
	}
	
	for (i = 0; i < N; i++)
		sort(nd[i].connected, nd[i].connected + nd[i].cnum);

	q.push(V);

	DFS(V);

	cout << "\n";
	while (!q.empty()){
		ta = q.front();
		q.pop();
		if (nd[ta].bfschk) continue;
		cout << ta << " ";
		nd[ta].bfschk = true;

		for (i = 0; i < nd[ta].cnum; i++)
			q.push(nd[ta].connected[i]);

	}

	return 0;
}
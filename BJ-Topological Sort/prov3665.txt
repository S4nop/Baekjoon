#include <bits/stdc++.h>

using namespace std;
struct node{
	int Hnum;
	int rank;
	int tnum;
} team[505], orgteam[505];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, N, M, i, ta, tb;
	bool possible = true;
	cin >> T;
	while (T--){
		cin >> N;
		for (i = 0; i < N; i++){
			cin >> ta;
			team[ta].rank = i;
			team[ta].tnum = ta;
			orgteam[ta].rank = i;
			team[ta].Hnum = i;
			orgteam[ta].Hnum = i;
		}

		cin >> M;
		for (i = 0; i < M; i++){
			cin >> ta >> tb;
            if(team[ta].rank > team[tb].rank != orgteam[ta].rank > orgteam[tb].rank) continue;
			if (team[ta].rank > team[tb].rank){
				team[ta].Hnum -= 1;
				team[tb].Hnum += 1;
			}
			else{
				team[ta].Hnum += 1;
				team[tb].Hnum -= 1;
			}
			swap(team[ta].rank, team[tb].rank);
		}

		for (i = 1; i <= N; i++){
			if (team[i].rank != team[i].Hnum) {
				cout << "Impossible\n";
				possible = false;
				break;
			}				
		}
		if (possible){
			sort(team + 1, team + N + 1, [](node a, node b){return a.rank > b.rank; });

			for (i = 1; i <= N; i++){
				cout << team[i].tnum << " ";

				cout << "\n";
			}
		}
		possible = true;
	}
}
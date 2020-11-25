#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	int N, M, ans_M, K, tmp, p, plist[55][55], chk = 0, fin = 0;
	set<int> s;
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++){
		cin >> tmp;
		s.insert(tmp);
	}
	ans_M = M;
	memset(plist, -1, sizeof(plist));

	for (int i = 0; i < M; i++){
		cin >> plist[i][0];
		chk = 0;
		for (int j = 1; j <= plist[i][0]; j++){
			cin >> plist[i][j];
			if (s.find(plist[i][j]) != s.end()) chk = 1;
		}
		if (chk){
			for (int j = 1; j <= plist[i][0]; j++)
				s.insert(plist[i][j]);
			--ans_M;
			plist[i][0] = -1;
		}
	}

	while (!fin){
		fin = 1;
		for (int i = 0; i < M; i++){
			if (plist[i][0] == -1) continue;
			chk = 0;
			for (int j = 1; j <= plist[i][0]; j++)
			if (s.find(plist[i][j]) != s.end()) chk = 1;
			if (chk){
				for (int j = 1; j <= plist[i][0]; j++)
					s.insert(plist[i][j]);
				--ans_M;
				plist[i][0] = -1;
				fin = 0;
			}
		}
	}
	cout << ans_M;
}
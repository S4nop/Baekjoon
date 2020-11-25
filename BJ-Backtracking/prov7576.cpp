#include <bits/stdc++.h>

#define bfsWithPoint(y, x) if (!box[y][x + 1]) {\
								box[y][x] = 1; \
								bitm |= x + 1 << 16;\
								bitm |= y;	\
								st.first = bitm; \
								st.second = tn + 1; \
								q.push(st); \
								bitm = 0;	\
							}

using namespace std;

pair<int, int> st;
queue<pair<int, int>> q;

int box[1010][1010];
int main(){
	ios_base::sync_with_stdio(0);
	int M, N, i, j, bitm = 0, tx, ty, tn, ans = -1;
	cin >> M >> N;
	memset(box, -1, sizeof(int)* 1010 * 1010);
	st.second = 0;
	for (i = 1; i <= N; i++){
		for (j = 1; j <= M; j++){
			cin >> box[i][j];
			if (box[i][j] == 1){
				bitm |= j << 16;
				bitm |= i;
				st.first = bitm;
				q.push(st);
				bitm = 0;
			}
		}
	}

	while (!q.empty()){
		tx = ((q.front().first & ~0xFFFF) >> 16);
		ty = (q.front().first & 0xFFFF);
		tn = q.front().second;
		q.pop();
		ans = max(tn, ans);
		bfsWithPoint(ty, tx + 1)
		bfsWithPoint(ty, tx - 1)
		bfsWithPoint(ty + 1, tx)
		bfsWithPoint(ty - 1, tx)
	}
	for (i = 1; i <= N; i++){
		for (j = 1; j <= M; j++){
			if (!box[i][j]){
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans;
}
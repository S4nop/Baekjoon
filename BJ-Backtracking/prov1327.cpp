#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>

using namespace std;

int ans, k, N;

pair<int, int> sat;
queue<int> Q;
map<int, int> m;

int BFS(){
	int i, tmp, n, j, cnt = 0, sv;
	while (!Q.empty()){
		n = Q.front();
		Q.pop();
		cnt = m[n];
		for (j = 0; j <= N - k; j++){
			sv = n;	tmp = 0;

			for (i = 0; i < k / 2; i++){
				tmp = (sv & (0xF << (4 * (N - i - j - 1)))) >> (4 * (N - i - j - 1));
				sv &= ~(0xF << (4 * (N - i - j - 1)));
				sv |= ((sv & (0xF << (4 * (N - k + i - j)))) << (4 * (k - 2 * i - 1)));
				sv &= ~(0xf << 4 * (N - k + i - j));
				sv |= ((tmp << 4 * (N - k + i - j)) & (0xf << 4*(N-k+i-j)));
			}
			if (m[sv] == 0){
				m[sv] = cnt + 1;
				Q.push(sv);
			}
		}
	}
	return m.count(ans) ? m[ans] : -1;
}

int main(){
	ios_base::sync_with_stdio(0);
	int s[10], i = 0, n = 0;
	cin >> N >> k;
	for (i = 0; i < N; i++)
		cin >> s[i];

	for (i = 0; i < N; i++)
		n |= (s[i] << (4 * (N - i - 1)));

	sort(s, s + N);

	for (i = 0; i < N; i++)
		ans |= (s[i] << (4 * (N - i - 1)));

	if (n == ans){
		cout << 0;
		return 0;
	}
	m[n] = 0;
	Q.push(n);
	cout << BFS();

}
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	int select;
	int schk;
    int cnt;
	bool chk;
} num[100100];

int DFS(node &nd, int startn, int popul){
	nd.chk = true; nd.cnt = popul;
	if (nd.select - 1 == startn) return popul + 1;
	if (num[nd.select - 1].chk){
		if (num[nd.select - 1].schk == nd.schk){
			num[nd.select - 1].schk = nd.schk;
			return popul - num[nd.select - 1].cnt + 1;
		}
		else{
			return 0;
		}
	}
	else{
		num[nd.select - 1].schk = nd.schk;
		return DFS(num[nd.select - 1], startn, popul + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	int T, n, i, ans = 0;
	cin >> T;
	while (T--){
		cin >> n;
		ans = n;
		for (i = 0; i < n; i++){
			num[i].chk = false;
			cin >> num[i].select;
		}

		for (i = 0; i < n; i++){
			if (!num[i].chk) {
				num[i].schk = i;
				ans -= DFS(num[i], i, 0);
			}
		}
		cout << ans << "\n";
	}
}
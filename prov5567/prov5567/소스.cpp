#include <cstdio>                                                                                    
#include <iostream>
#include <algorithm>

using namespace std;

struct Fr{
	int id;
	int n;
	Fr * frnd[505];
	bool call;
};
Fr F[505];
int rslt;

void dfs(int n, int h){
	if (h == 3) return;
	//rslt++;
	if (F[n].call == false) {
		rslt++;
		F[n].call = true;
	}
	for (int i = 0; i < F[n].n; i++){
		dfs(F[n].frnd[i]->id, h + 1);
	}
}

int main(){
	int n, m, i;
	int tmpa, tmpb;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++){
		scanf("%d %d", &tmpa, &tmpb);
		F[tmpa].frnd[F[tmpa].n] = &F[tmpb];
		F[tmpa].n++;
		F[tmpb].call = false;
		F[tmpa].id = tmpa;
		F[tmpb].frnd[F[tmpb].n] = &F[tmpa];
		F[tmpb].n++;
		F[tmpa].call = false;
		F[tmpa].id = tmpa;
		F[tmpb].id = tmpb;
	}
	dfs(1, 0);

	printf("%d", rslt - 1);

	return 0;
}

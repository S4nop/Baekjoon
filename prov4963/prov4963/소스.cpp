#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

vector<int> rslt;

int wrd[55][55];
int wnt[55][55];
int chk[55][55];
int nowrslt;
void getrslt(int x, int y, bool con){
	if (wrd[x][y] == 1 && chk[x][y] == 0 && wnt[x][y] == 0 && con == false) {
		nowrslt++;
		chk[x][y] = 1;
	}
	if (con) {
		chk[x][y] = 1;
	}
	else{
		wnt[x][y] = 1;
	}
	if (wrd[x][y] == 1){
		for (int i = -1; i <= 1; i++){
			for (int j = -1; j <= 1; j++){
				if (chk[x + i][y + j] == 0 && wrd[x + i][y + j] == 1) getrslt(x + i, y + j, true);
			}
		}
	}
	if (!con){
		for (int i = -1; i <= 1; i++){
			for (int j = -1; j <= 1; j++){
				if (wnt[x + i][y + j] == 0) getrslt(x + i, y + j, false);
			}
		}
	}


}

int main(){
	int w, h;
	while (1){
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) break;
		memset(wnt, -1, sizeof(int)* 55 * 55);
		memset(chk, 0, sizeof(int)* 55 * 55);
		memset(wrd, 0, sizeof(int)* 55 * 55);
		for (int i = 1; i <= h; i++){
			for (int j = 1; j <= w; j++){
				scanf("%d", &wrd[i][j]);
				wnt[i][j] = 0;
			}
		}
		getrslt(1, 1, 0);
		rslt.push_back(nowrslt);
		nowrslt = 0;
	}

	for (int i = 0; i < rslt.size(); i++){
		printf("%d\n", rslt[i]);
	}
	return 0;
}
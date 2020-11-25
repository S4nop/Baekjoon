#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int cost[22][22];
int routchk[22][22];
int main(){
	int n, sum = 0, chksum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &cost[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cost[i][j] != cost[j][i]) {
				cout << "-1";
				return 0;
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				if (cost[i][k] > cost[i][j] + cost[j][k]){
					cout << "-1";
					return 0;
				}
				if (j != k && i != j && cost[i][k] == cost[i][j] + cost[j][k]) { routchk[i][k] = 1; }
				
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (routchk[i][j] == 0) sum += cost[i][j];
		}
	}
	printf("%d", sum / 2);
}
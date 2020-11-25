#include <bits/stdc++.h>

#define N 4
using namespace std;

//direc : -1 = left, 1 = right
void normalRot(int Mat[][4], int direc, int count){
	count %= 4;
	if (!count) return;
	int newMat[N][N];
	if (count == 3) direc *= -1; count = 1;

	int * ps = *Mat, *pd = *newMat, i, j;

	if (direc == -1){
		pd += (N * (N - 1));
		for (i = 0; i < N; i++){
			for (j = 0; j < N; j++){
				*pd = *ps++;
				pd -= N;
			}
			pd += (N * N + 1);
		}
	}
	else{
		pd += (N - 1);
		for (i = 0; i < N; i++){
			for (j = 0; j < N; j++){
				*pd = *ps++;
				pd += N;
			}
			pd -= (N * N + 1);
		}
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			*(Mat[i] + j) = newMat[i][j];
		}
	}

	return;
}

int main(){
	int Mat[N][N];
	srand(time(NULL));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			Mat[i][j] = rand() % 100;
		}
	}

	cout << "[";
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cout << Mat[i][j] << "., ";
		}
	}
	cout << "]\n";

	normalRot(Mat, -1, 1);

	cout << "[";
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cout << Mat[i][j] << "., ";
		}
	}
	cout << "]\n";

	return 0;
}
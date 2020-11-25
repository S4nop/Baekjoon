#include <iostream>
#include <cstring>

using namespace std;

char map[3072][8000], stars[3][5] = { { ' ', ' ', '*', ' ', ' ' }, { ' ', '*', ' ', '*', ' ' }, { '*', '*', '*', '*', '*' } };

void makeStars(int n, int x, int y){
	if (n > 1){
		makeStars(n / 2, x + 3 * n / 2, y);
		makeStars(n / 2, x, y + 3 * n / 2);
		makeStars(n / 2, x + 3 * n, y + 3 * n / 2);
	}
	else if (n == 1){
		for (int i = 0; i < 3; i++) strncpy(map[y + i] + x, stars[i], 5);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		fill(map[i], map[i] + sizeof(char)* N * 3, ' ');
		makeStars(N / 3, 0, 0);

	for (int i = 0; i < N; i++)
		cout << map[i] << "\n";
}
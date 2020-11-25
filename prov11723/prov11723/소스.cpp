#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	string tmp;
	int t;
	int data = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		cin >> tmp;
		if (tmp == "add") {
			scanf("%d", &t);
			data |= (1 << t);
		}
		else if (tmp == "check"){
			scanf("%d", &t);
			printf("%d\n", (data & (1 << t)) == 0 ? 0 : 1);
		}
		else if (tmp == "remove"){
			scanf("%d", &t);
			data &= ~(1 << t);
		}
		else if (tmp == "toggle"){
			scanf("%d", &t);
			data ^= (1 << t);
		}
		else if (tmp == "all") data = ((1 << 21) - 1);
		else if (tmp == "empty") data = 0;

	}

	return 0;
}

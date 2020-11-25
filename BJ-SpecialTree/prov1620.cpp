#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <cctype>

using namespace std;

pair<char*, int> book[100100];
char namebook[100100][21];

int compPair(pair<char*, int> a, pair<char*, int> b){
	return strcmp(a.first, b.first) < 0;
}

int main(){
	int N, M, i, tname, tstart, tend, tmid; char tb[21];
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++){
		scanf("%s", &namebook[i + 1]);
		book[i + 1] = make_pair(namebook[i + 1], i + 1);
	}
	sort(book + 1, book + N + 1, compPair);
	
	for (i = 0, tstart = 1, tend = N; i < M; i++, tstart = 1, tend = N){
		scanf("%s", &tb);
		if (tb[0] <= '9') printf("%s\n",namebook[atoi(tb)]);
		else{
			tname = strcmp(book[tmid = (tend + tstart) / 2].first, tb);
			while (tname){
				if (tname < 0) tstart = tmid + 1;
				else tend = tmid - 1;
				tname = strcmp(book[tmid = (tend + tstart) / 2].first, tb);
			}
			printf("%d\n",book[tmid].second);
		}
	}


	return 0;
}
#include <bits/stdc++.h>

using namespace std;

pair<int, char> cnt[26];
int val[26];

int main(){
	ios_base::sync_with_stdio(0);
	int N, len;
	char inp[10][10];

	cin >> N;
	for (int i = 0; i < 26; i++) cnt[i] = make_pair(0, i + 'A');
	for (int i = 0; i < N; i++){
		cin >> inp[i];
		len = strlen(inp[i]);
		for (int j = 0; j < len; j++){
			cnt[inp[i][len - j - 1] - 'A'].first += pow(10, j);
		}
	}

	sort(cnt, cnt + 26, greater<pair<int, char>>());

	for (int i = 0; i < 26; i++){
		val[cnt[i].second - 'A'] = 9 - i;
	}

	long long sum = 0;

	for (int i = 0; i < N; i++){
		len = strlen(inp[i]);
		for (int j = 0; j < len; j++){
			sum += val[inp[i][len - j - 1] - 'A'] * pow(10, j);
		}
	}

	cout << sum;

}
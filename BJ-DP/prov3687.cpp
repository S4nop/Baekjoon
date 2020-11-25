#include <bits/stdc++.h>

#define addNum (1 << 24)
#define getNum(x) ((x >> 24) & 0xef)
#define getEight(x) ((x >> 18) & 0x3f)
#define getZero(x) ((x >> 12) & 0x3f)
#define getTwo(x) ((x >> 6) & 0x3f)
#define getOne(x) (x & 0x3f)
#define getithBit(x, i) ((x >> i - 1) & 1)
using namespace std;

int stickNum[4] = { 7, 5, 6, 2 };
int bitNum[4] = { 1 << 18, 1 << 6, 1 << 12, 1 };

int dp[110];

int useStick(int n){
	if (!n) return addNum;
	if (dp[n] != -1) return dp[n];
	int i, j, tmpa, tmpb;
	int data, chkmin = 0xffffffff;
	for (i = 0; i < 4; i++){
		if (n >= stickNum[i]){
			data = useStick(n - stickNum[i]);
			if (data == 0xffffffff) continue;
			else data += bitNum[i];
			tmpa = getNum(data); tmpb = getNum(chkmin);
			if (tmpa == tmpb){
				for (j = 0; j < 24; j++){
					if (getithBit(data, j) > getithBit(chkmin, j)){
						chkmin = data;
						break;
					}
					else if (getithBit(data, j) < getithBit(chkmin, j)){
						break;
					}
				}
			}
			else chkmin = tmpa >= tmpb ? chkmin : data;
		}
	}
	return dp[n] = chkmin == 0xffffffff ? chkmin : chkmin + addNum;
}

int main(){
	ios_base::sync_with_stdio(0);
	int T, N, ans, e, t, z, o, i;
	cin >> T;
	memset(dp, -1, sizeof(int)* 110);
	while (T--){
		cin >> N;
		if (N == 3){
			cout << "7 7\n"; continue;
		}
		if (N == 4){
			cout << "4 11\n"; continue;
		}
		ans = useStick(N);
		e = getEight(ans);
		t = getTwo(ans);
		z = getZero(ans);
		o = getOne(ans);
		if (!o && !t){
			if (z) cout << "6";
			for (i = 0; i < z - 1; i++) cout << "0";
			for (i = 0; i < e; i++) cout << "8";
			cout << " ";
		}
		else{
			for (i = 0; i < o; i++) cout << "1";
			for (i = 0; i < t; i++) cout << "2";
			for (i = 0; i < z; i++) cout << "0";
			for (i = 0; i < e; i++) cout << "8";
			cout << " ";
		}

		if (N % 2){
			cout << "7";
			for (i = 0; i < N / 2 - 1; i++) cout << "1";
			cout << "\n";
		}
		else{
			for (i = 0; i < N / 2; i++) cout << "1";
			cout << "\n";
		}
	}
}
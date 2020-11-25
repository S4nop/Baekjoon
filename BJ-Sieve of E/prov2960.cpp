#include <bits/stdc++.h>

using namespace std;

unsigned char sieve[1015 / 8];

inline bool isPrime(int k){
	return sieve[k / 8] & (1 << (k % 8));
}

inline void chkNotPrime(int k){
	sieve[k / 8] ^= (1 << (k % 8));
}

int main(){
	ios_base::sync_with_stdio(0);
	int N, K, i, j, ans = 0;
	cin >> N >> K;
	memset(sieve, 255, sizeof(sieve));
	for (i = 2; i <= N; ++i){
		if (isPrime(i)){
			if (++ans == K){
				cout << i;
				return 0;
			}
			for (j = i*i; j <= N; j += i){
				if (isPrime(j)){
					chkNotPrime(j);
					if (++ans == K){
						cout << j;
						return 0;
					}
				}
			}
		}
	}
}
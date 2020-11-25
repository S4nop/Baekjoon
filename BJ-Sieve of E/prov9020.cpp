#include <bits/stdc++.h>
using namespace std;

unsigned char sieve[1000015 / 8];

bool isPrime(int n){
	return sieve[n / 8] & (1 << (n % 8));
}

void chkNotPrime(int n){
	sieve[n / 8] ^= (1 << (n % 8));
}

int main(){
	int M, N, ans = 0, sqrtn;
	unsigned long long i, j;
	memset(sieve, 255, sizeof(sieve));
	cin >> N;
    sqrtn = sqrt(N);
	for (i = 2; i <= sqrtn; i++){
		if (isPrime(i)){
			for (j = i*i; j <= N; j += i){
				if (isPrime(j)) chkNotPrime(j);
			}
		}
	}

	chkNotPrime(1);

    cin >> M;
    while(M){
        for (i = M; i <= 2*M; i++){
            if (isPrime(i)) ans++;
        }
        cout << ans << "\n";
        ans = 0;
    }



}
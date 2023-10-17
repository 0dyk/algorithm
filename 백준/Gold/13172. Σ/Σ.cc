#include <iostream>
#define MOD 1000000007
using namespace std;

int M;

// b / a -> a * b^-1 MOD X
// b^-2 = n^-1 MOD X
// n^-1 MOD X = b^(X-2) MOD X

// x를 p승한다~
long long mypow(long long x, long long p) {
	
	long long ret = 1;
	while (p) {
		if (p % 2 == 1) ret = ret * x % MOD;
		p /= 2;
		x = x * x % MOD;
	}

	return ret % MOD;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M;

	long long res = 0;
	long long N, S;

	for (int i = 0; i < M; ++i) {
		// N면체, 모든 면에 적힌 수의 합 S -> 기대값 : N / S
		cin >> N >> S;

		// S / N = S * N^-1 mod MOD
		// S / N = S * N^(MOD - 2) mod MOD
		res += (S * mypow(N, MOD - 2)) % MOD;
	}

	cout << res % MOD<< '\n';

	return 0;
}
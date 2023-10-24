#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
bool primeNum[4000001];

// 소수들
vector<int> v;

// 중복검사
int checkCount[4000001];

// 에라토스테네스의 체
void calcPrimeNumber() {
	for (int i = 2; i <= N; ++i) primeNum[i] = true;
	
	for (int i = 2; i <= sqrt(N); ++i) {
		if (!primeNum[i]) continue;

		for (int j = i * i; j <= N; j += i) primeNum[j] = false;
	}

	// V에 저장하기
	for (int i = 2; i <= N; ++i) {
		if (!primeNum[i]) continue;
		v.push_back(i);
	}
}

int main() {
	cin >> N;

	// 에라토스테네스의 체 O(N^(1/2))
	calcPrimeNumber();

	for (int i = 0; i < v.size(); ++i) {
		int res = v[i];
		++checkCount[res];
		for (int j = i + 1; j < v.size(); ++j) {
			res += v[j];
			if (res > N) break;
			++checkCount[res];
		}
	}

	cout << checkCount[N] << '\n';

	return 0;
}
#include<iostream>
#include<vector>
#define MOD 1000000

using namespace std;

typedef vector<vector<long long>> matrix;
long long n;

matrix operator*(matrix& a, matrix& b) {
	matrix tmp(2, vector<long long>(2));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				tmp[i][j] += a[i][k] * b[k][j];
			}
			tmp[i][j] %= MOD;
		}
	}

	return tmp;
}

int main() {
	cin >> n;

	matrix mt = { {1,0}, {0,1} };
	matrix a = { {1,1}, {1,0} };

	while (n > 0) {
		if(n % 2 == 1){
			mt = mt * a;
		}
		a = a * a;
		n /= 2;
	}

	cout << mt[0][1];

	return 0;
}
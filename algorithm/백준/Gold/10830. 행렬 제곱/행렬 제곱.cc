#include<iostream>
using namespace std;

int N; long long B;
int arr[5][5]; // 초기값
int brr[5][5]; // 변화값

/*
 * 행렬 * 행렬
 */
void gobSem(int i) {
	int tmp[5][5] = { 0, };

	if (i) {	// brr * brr
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					tmp[i][j] += brr[k][j] * brr[i][k];
	}
	else {	// arr * brr
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					tmp[i][j] += arr[i][k] *brr[k][j];
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			brr[i][j] = tmp[i][j] % 1000;
}

/*
 * 분할정복?
 */
void getSum(long long n) {
	if (n == 1) return;

	if (n & 1) {
		getSum(n / 2);
		gobSem(1);	// brr = brr * brr;
		gobSem(0);	// brr = arr * brr;
	}
	else {
		getSum(n / 2);
		gobSem(1);	// brr = brr * brr;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			brr[i][j] = arr[i][j];
		}
	}

	getSum(B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << brr[i][j] % 1000;
			if (j != N - 1) cout << ' ';
			else cout << '\n';
		}
	}

	return 0;
}
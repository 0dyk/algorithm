#include <iostream>

using namespace std;

int n, m;
int arr[2][10000001] = { 0 }, brr[500001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;

		if (tmp < 0) {
			arr[0][tmp*(-1)]++;
		}
		else {
			arr[1][tmp]++;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		if (tmp < 0) {
			brr[i] = arr[0][tmp * (- 1)];
		}
		else {
			brr[i] = arr[1][tmp];
		}
	}

	for (int i = 0; i < m; i++) {
		cout << brr[i] << ' ';
	}

	return 0;
}
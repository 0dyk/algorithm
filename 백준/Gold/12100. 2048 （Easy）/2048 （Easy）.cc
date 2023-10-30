#include<iostream>
#include<queue>
using namespace std;

int N;

int crr[21][21];

int res;

void rotate(int cnt, int arr[21][21]) {
	// 기저조건
	if (cnt == 5) {
		int maxV = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (arr[i][j] > maxV) maxV = arr[i][j];
			}
		}

		if (maxV > res) res = maxV;
		return;
	}

	int brr[21][21];
	queue<int> q;

	// 위
	// 1. 복사
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			brr[i][j] = arr[i][j];
		}
	}

	// 2. 밀땅
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < N; ++i) {
			if (brr[i][j] != 0) q.push(brr[i][j]);
		}
		
		for (int i = 0; i < N; ++i) {
			if (!q.empty()) {
				brr[i][j] = q.front();
				q.pop();
				
				if (!q.empty() && brr[i][j] == q.front()) {
					brr[i][j] *= 2;
					q.pop();
				}
			}
			else {
				brr[i][j] = 0;
			}
		}
	}

	rotate(cnt + 1, brr);

	// 아래
	// 1. 복사
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			brr[i][j] = arr[i][j];
		}
	}

	// 2. 밀땅
	for (int j = 0; j < N; ++j) {
		for (int i = N - 1; i >= 0; --i) {
			if (brr[i][j] != 0) q.push(brr[i][j]);
		}

		for (int i = N - 1; i >= 0; --i) {
			if (!q.empty()) {
				brr[i][j] = q.front();
				q.pop();

				if (!q.empty() && brr[i][j] == q.front()) {
					brr[i][j] *= 2;
					q.pop();
				}
			}
			else {
				brr[i][j] = 0;
			}
		}
	}

	rotate(cnt + 1, brr);


	// 왼
	// 1. 복사
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			brr[i][j] = arr[i][j];
		}
	}

	// 2. 밀땅
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (brr[i][j] != 0) q.push(brr[i][j]);
		}

		for (int j = 0; j < N; ++j) {
			if (!q.empty()) {
				brr[i][j] = q.front();
				q.pop();

				if (!q.empty() && brr[i][j] == q.front()) {
					brr[i][j] *= 2;
					q.pop();
				}
			}
			else {
				brr[i][j] = 0;
			}
		}
	}

	rotate(cnt + 1, brr);


	// 우
	// 1. 복사
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			brr[i][j] = arr[i][j];
		}
	}

	// 2. 밀땅
	for (int i = 0; i < N; ++i) {
		for (int j = N - 1; j >= 0; --j) {
			if (brr[i][j] != 0) q.push(brr[i][j]);
		}

		for (int j = N - 1; j >= 0; --j) {
			if (!q.empty()) {
				brr[i][j] = q.front();
				q.pop();

				if (!q.empty() && brr[i][j] == q.front()) {
					brr[i][j] *= 2;
					q.pop();
				}
			}
			else {
				brr[i][j] = 0;
			}
		}
	}

	rotate(cnt + 1, brr);

}

void solve() {

	rotate(0, crr);

}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> crr[i][j];

	solve();

	cout << res << '\n';

}
#include<iostream>
#include<vector>
using namespace std;

// 0 : 중간, 1 : 상, 2 : 좌, 3 : 하, 4 : 우

int N;
int dp[5][5][100001];

vector<int> v;

int point(int from, int to) {
	if (from == 0) return 2;
	if (from == to) return 1;
	if (from - to == 2 || from - to == -2) return 4;
	return 3;
}

int solve(int x, int y, int cnt) {
	// 기저조건
	if (cnt == N) return 0;

	// 이미 계산된 경우
	if (dp[x][y][cnt] != -1) return dp[x][y][cnt];

	// 왼발 움직인 경우
	int left = solve(v[cnt], y, cnt + 1) + point(x, v[cnt]);
	
	// 오른발 움직인 경우
	int right = solve(x, v[cnt], cnt + 1) + point(y, v[cnt]);
	
	// return
	return dp[x][y][cnt] = left < right ? left : right;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (true) {
		int tmp; cin >> tmp;
		if (tmp == 0) break;
		v.push_back(tmp);
	}

	N = v.size();
	for (int k = 0; k < N; ++k)
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j)
				dp[i][j][k] = -1;

	cout << solve(0, 0, 0) << '\n';

	return 0;
}
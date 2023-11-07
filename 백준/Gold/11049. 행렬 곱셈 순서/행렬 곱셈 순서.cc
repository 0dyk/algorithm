#include<iostream>
#include<vector>
#include<algorithm>
#define INF 1987654321
using namespace std;

int N;

int dp[501][501];

vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	int r, c;
	for (int i = 0; i < N; ++i) {
		cin >> r >> c;
		v.push_back({ r, c});
	}

	for (int d = 1; d < N; ++d) {
		for (int i = 0; i < N - d; ++i) {
			dp[i][i + d] = INF;
			for (int j = i; j < i + d; ++j) {
				dp[i][i + d] = min(dp[i][i + d], dp[i][j] + dp[j + 1][i + d] + v[i].first * v[j].second * v[i + d].second);
			}
		}
	}

	cout << dp[0][N - 1] << '\n';

	return 0;
}
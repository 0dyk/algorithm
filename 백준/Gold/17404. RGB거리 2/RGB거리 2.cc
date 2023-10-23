#include<iostream>
#include<algorithm>
#define INF 1987654321
using namespace std;

int N;

// 빨강, 초록, 파랑으로 칠하는 비용
int arr[1001][3];

int dp[1001][3];

int answer;

void solve(int k) {
	// 초기화
	dp[1][0] = dp[1][1] = dp[1][2] = INF;
	for (int i = 2; i <= N; ++i) {
		dp[i][0] = dp[i][1] = dp[i][2] = 0;
	}

	// 1번 집의 색깔 k
	dp[1][k] = arr[1][k];
	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j < 3; ++j) {
			// 0은 1과 2 체크
			dp[i][0] = min(dp[i - 1][1] + arr[i][0], dp[i - 1][2] + arr[i][0]);

			// 1은 0과 2 체크
			dp[i][1] = min(dp[i - 1][0] + arr[i][1], dp[i - 1][2] + arr[i][1]);

			// 2는 0과 1 체크
			dp[i][2] = min(dp[i - 1][0] + arr[i][2], dp[i - 1][1] + arr[i][2]);
		}
	}

	// 1번집과 색이 다른 집 중 최소값
	for (int i = 0; i < 3; ++i) {
		if (i == k) continue;
		answer = min(answer, dp[N][i]);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> arr[i][j];
		}
	}

	// 1번 != 2번 / 1번 != N번 / N-1번 != N번
	// 양 옆의 집과는 달라야 한다.

	// 1, 2번 N-1번 N번 집
	// 1번집 색깔을 정하고 start 하자
	
	answer = INF;

	for (int i = 0; i < 3; ++i) {
		solve(i);
	}

	cout << answer << '\n';

	return 0;
}
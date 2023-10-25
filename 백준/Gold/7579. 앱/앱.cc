#include <iostream>
#include <algorithm>

using namespace std;

// 크기 N, 필요한 메모리 M
int N, M;

struct App{
	int memory;
	int cost;
};

App app[101];

// dp[c] -> c의 비용으로 얻을 수 있는 최대의 메모리
int dp[10001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	int sum = 0;
	for (int i = 1; i <= N; ++i) cin >> app[i].memory;
	for (int i = 1; i <= N; ++i) { cin >> app[i].cost; sum += app[i].cost; }

	// 비용이 작은 순으로 정렬
	sort(app + 1, app + N + 1, [](App a, App b) -> bool {return a.cost < b.cost; });

	for (int i = 1; i <= N; ++i){
		// 갱신된 값이 사용되는 것을 방지하기 위해서
		// j가 sum -> app[i].cost로 내려가면서 체크
		for(int j = sum; j >= app[i].cost; --j){
			// app[i].cost ~ 10000까지
			// 최대값 체크
			int next = dp[j - app[i].cost] + app[i].memory;
			if (dp[j] < next) dp[j] = next;
		}
	}

	// 결과값 찾기
	for (int i = 0; i <= sum; ++i) {
		if (dp[i] >= M) {
			cout << i << '\n';
			break;
		}
	}

	return 0;
}
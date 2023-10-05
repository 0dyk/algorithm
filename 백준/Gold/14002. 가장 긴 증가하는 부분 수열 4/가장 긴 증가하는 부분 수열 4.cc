#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 크기
int N;

// 배열 저장
int arr[1001];

// dp[k] -> k 이전의 원소(LIS에서)
int dp[1001];

// LIS 길이, 최대값이 idx
int maxLength, maxIdx;

// 정답 배열
vector<int> v;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	maxLength = 0, maxIdx = 0;
	int idx;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];

		idx = 0;
		for (int j = 1; j < i; j++) {
			// 이전까지의 원소 중에서 지금 입력받은 값보다 작은 값이 존재하면
			// 인덱스 = dp[j]에 저장된 인덱스 값 가져오기
			// 그 중 가장 큰 값 -> 가장 뒤에 놈을 업데이트 하려고

			if (arr[j] < arr[i]) idx = dp[j] > idx ? dp[j] : idx;
		}
		
		// 인덱스 저장
		dp[i] = idx + 1;
		
		// 길이가 늘어난 경우
		if (maxLength < idx + 1) {
			maxLength = idx + 1;
			maxIdx = i;
		}
	}

	for (int cur = maxIdx, len = maxLength; cur >= 1; cur--) {
		if (dp[cur] == len) {
			v.push_back(arr[cur]);
			len--;
		}
	}

	cout << maxLength << '\n';

	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i];
		if (i != 0)cout << ' ';
		else cout << '\n';
	}

	return 0;
}
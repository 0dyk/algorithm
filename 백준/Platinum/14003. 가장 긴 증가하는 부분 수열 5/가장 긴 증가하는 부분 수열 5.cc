#include<iostream>
#include<vector>
#include<algorithm>
#define MAXN 1000010

using namespace std;

// 크기
int N;

// 배열 저장
int arr[MAXN];

int dp[MAXN];

// 수열
vector<int> v;

// 결과값 저장
vector<int> res;

// 길이, 맥스값 idx
int len, idx;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	len = 0; idx = 0;
	for (int i = 1; i <= N; i++) 
	{
		cin >> arr[i];
		if (v.size() == 0) 
		{
			v.push_back(arr[i]);
			dp[i] = 1;
		}
		else 
		{
			// 마지막 원소보다 큰 경우 -> 길이가 늘어난 경우
			if (v[v.size() - 1] < arr[i]) 
			{
				v.push_back(arr[i]);
				dp[i] = v.size();
			}
			else 
			{
				// 길이가 늘어나지 않는 경우 체크
				auto iter = lower_bound(v.begin(), v.end(), arr[i]);
				
				*iter = arr[i];

				dp[i] = iter - v.begin() + 1;
			}
		}

		// 길이가 늘어난 경우
		if (dp[i] > len) {
			idx = i;
			len = dp[i];
		}
	}

	res.push_back(arr[idx]);
	for (int i = idx - 1; i > 0; i--) {
		if (arr[i] < arr[idx] && dp[i] + 1 == dp[idx]) {
			res.push_back(arr[i]);
			idx = i;
		}
	}

	// 출력
	cout << len << '\n';
	for (int i = res.size() - 1; i >= 0; i--) {
		cout << res[i];
		if (i != 0) cout << ' ';
		else cout << '\n';
	}

	return 0;
}
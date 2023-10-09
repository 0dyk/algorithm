#include<iostream>
#include<vector>
#include<algorithm>
#define MAXN 1000001

using namespace std;

// 크기
int N;

// 배열 저장
int arr[MAXN];

// 수열
vector<int> v;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (v.size() == 0) v.push_back(arr[i]);
		else {
			// 마지막 원소보다 큰 경우 -> 길이가 늘어난 경우
			if (v[v.size() - 1] < arr[i]) v.push_back(arr[i]);
			else {
				// 아닌 경우에는 해당 자리 값 갱신?
				*(lower_bound(v.begin(), v.end(), arr[i])) = arr[i];
			}
		}
	}

	cout << v.size() << '\n';

	return 0;
}
#include<iostream>

using namespace std;

// 수열, 질문의 수
int N, M;

// 수열
int arr[2001];

// 팰린드롬?
bool isPalindrom[2001][2001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		
		// 한자리 수는 무조건 팰린드롬
		isPalindrom[i][i] = true;

		// 두 자리수 체크
		if (i != 1 && arr[i] == arr[i - 1]) isPalindrom[i - 1][i] = true;
	}

	// 팰린드롬 체크

	// i는 회문의 길이
	// i가 0, 1인 경우는 체크되어있음.
	for (int i = 2; i <= N - 1; ++i) {
		// j ~ i + j까지 회문인지 체크하기
		for (int j = 1; i + j <= N; ++j) {
			if (arr[j] == arr[i + j] && isPalindrom[j + 1][i + j - 1]) {
				isPalindrom[j][i + j] = true;
			}
		}
	}

	cin >> M;

	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;

		if (isPalindrom[a][b]) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}
#include<iostream>

using namespace std;

// 플레이어 수
int N;

// 최대 값
int maxValue;

// 가지고 있는 카드 정보
int arr[100001];

// 카드가 있는지
bool isExist[1000001];

// 점수
int score[1000001];

void Eratosthenes() {
	// 플레이어 i
	for (int i = 1; i <= N; ++i) {
		// i의 카드 j, j의 배수
		for (int j = arr[i] * 2; j <= maxValue; j += arr[i]) {
			if (isExist[j]) {
				++score[arr[i]];
				--score[j];
			}
		}
	}
}

int main() {

	cin >> N;

	maxValue = 0;

	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		isExist[arr[i]] = true;

		if (arr[i] > maxValue) maxValue = arr[i];
	}

	// 에라토스테네스의 체
	Eratosthenes();

	for (int i = 1; i <= N; ++i) {
		cout << score[arr[i]] << '\n';
	}

	return 0;
}

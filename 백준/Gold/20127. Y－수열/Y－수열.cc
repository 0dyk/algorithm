#include <iostream>


using namespace std;

int main() {

	int N;
	cin >> N;


	int prev = 0;

	bool isUp = true;
	bool isDown = true;

	int firstValue;
	int tmp;

	int upIdx = 0;
	int downIdx = 0;

	for (int i = 0; i < N; ++i) {

		cin >> tmp;

		if (i != 0) {

			// 증가 수열 확인
			if (isUp && tmp < prev) { // 감소된 경우

				// 처음 감소
				if (upIdx == 0) {

					upIdx = i;
				}
				// 불가능
				else {

					isUp = false;
				}
			}


			// 감소 수열 확인
			if (tmp > prev) { // 증가된 경우

				// 처음 증가
				if (downIdx == 0) {

					downIdx = i;
				}
				// 불가능
				else {

					isDown = false;
				}
			}

		}
		else {
			firstValue = tmp;
		}

		prev = tmp;
	}

	// 2 1 1 1 1 1 1 1

	int answer = -1;

	// 증가 OK
	if (isUp) {
		
		if (upIdx == 0 || (upIdx != 0 && tmp <= firstValue)) {
			
			answer = upIdx;
		}
	}

	// 감소 OK
	if (isDown) {

		if (downIdx == 0 || (downIdx != 0 && tmp >= firstValue)) {

			if(answer == -1 || downIdx < answer) answer = downIdx;
		}
	}

	cout << answer << '\n';

	return 0;
}
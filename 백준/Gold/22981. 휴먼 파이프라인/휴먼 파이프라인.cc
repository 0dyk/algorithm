#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	long long K;
	cin >> N >> K;

	vector<long long> workSpeed;
	long long tmp;

	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		workSpeed.push_back(tmp);
	}

	sort(workSpeed.begin(), workSpeed.end());

	// 최소 작업 시간
	long long maxWorkSpeed = 0;

	for (int i = 1; i < N; ++i) {

		// 1팀 작업 속도
		long long ATeamWorkSpeed = workSpeed[0] * i;

		// 2팀 작업속도
		long long BTeamWorkSpeed = workSpeed[i] * (N - i);

		// 분당 작업 속도
		long long workSpeedPerMinute = ATeamWorkSpeed + BTeamWorkSpeed;

		// 작업 끝나는 시간
		if (workSpeedPerMinute > maxWorkSpeed) {
			maxWorkSpeed = workSpeedPerMinute;
		}
	}

	long long answer = K / maxWorkSpeed;
	if (K % maxWorkSpeed != 0) answer++;

	cout << answer << '\n';

	return 0;
}
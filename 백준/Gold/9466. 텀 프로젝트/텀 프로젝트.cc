#include<iostream>
#include<deque>
using namespace std;

// 학생 수
int N;

// 번호
int arr[100001];

// 방문배열
bool visited[100001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
		for (int i = 1; i <= N; ++i) { cin >> arr[i]; visited[i] = false; }


		// 사이클을 찾는 문제
		int cnt = 0;

		for (int i = 1; i <= N; ++i) {
			if (visited[i]) continue;
			visited[i] = true;

			deque<int> dq;
			dq.push_back(i);

			int x = i;

			while (true) {
				int nx = arr[x];
				
				// 이미 방문한 번호일 경우 STOP
				if (visited[nx]) {
					// 1. q에 nx가 있는지 확인
					while (!dq.empty() && dq.front() != nx) {
						dq.pop_front();
					}

					// 2. 찾을 경우 찾은 시점 -> 남아있는 dq만큼 ++cnt
					// dq가 남아 있으면
					if (!dq.empty()) {
						cnt += dq.size();
					}

					break;
				}
				else {
					// 아직 체크하지 않은 번호인 경우 NEXT
					visited[nx] = true;
					dq.push_back(nx);

					x = nx;
				}

			} //end::while

		}  // end::n

		cout << N - cnt << '\n';
	} // end::tc

	return 0;
}
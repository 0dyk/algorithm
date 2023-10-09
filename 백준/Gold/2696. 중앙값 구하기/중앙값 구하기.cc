#include<iostream>
#include<queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> upQ;
priority_queue<int, vector<int>, less<int>> downQ;

int N;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;

		while (!upQ.empty()) upQ.pop();
		while (!downQ.empty()) downQ.pop();

		cout << N / 2 + 1 << '\n';

		int a;
		for (int i = 0; i < N; i++) {
			cin >> a;
			
			if (i == 0) {
				downQ.push(a);
				cout << a << ' ';
				continue;
			}

			if (i % 2 == 1) {
				// upQ에 삽입.
				if (downQ.top() > a) {
					upQ.push(downQ.top());
					downQ.pop();
					downQ.push(a);
				}
				else {
					upQ.push(a);
				}
			}
			else {
				// 홀수 큐에 삽입.
				if (upQ.top() < a) {
					downQ.push(upQ.top());
					upQ.pop();
					upQ.push(a);
				}
				else {
					downQ.push(a);
				}

				cout << downQ.top() << ' ';
			}
		}
		cout << '\n';
	}


	return 0;
}
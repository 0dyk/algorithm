#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N, S;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> S;

	int minCnt = 100001;
	int a, sum = 0;
	
	deque<int> dq;
	for (int i = 0; i < N; i++) {
		cin >> a;
		dq.push_back(a);
		sum += a;
		
		while (sum >= S) {
			if (dq.size() < minCnt) minCnt = dq.size();
			sum -= dq.front();
			dq.pop_front();
		}
	}

	if (minCnt == 100001) minCnt = 0;
	cout << minCnt << '\n';

	return 0;
}
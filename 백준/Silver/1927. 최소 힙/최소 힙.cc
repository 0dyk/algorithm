#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> p_q;

	while (n--) {
		int tmp;
		cin >> tmp;

		if (tmp) {
			p_q.push(tmp);
		} 
		else{
			if (p_q.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << p_q.top() << '\n';
				p_q.pop();
			}
		}
	}

	return 0;
}
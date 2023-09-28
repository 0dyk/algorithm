#include<iostream>
using namespace std;

int N, M;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> M;
		int a, b;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
		}
		cout << N - 1 << '\n';
	}

	return 0;
}
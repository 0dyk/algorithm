#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct KEY{
	int num, time;
	char alp;

	KEY(int n, int t, char a) : num(n), time(t), alp(a) {}
};

vector<KEY> keys;

int main() {
	
	int N, M;
	cin >> N >> M;

	int a, b; char c;

	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> c;

		keys.push_back({ a, b, c });
	}

	sort(keys.begin(), keys.end(), [](const KEY& a, const KEY& b) {
		if (a.time == b.time) {
			return a.num < b.num;
		}
		return a.time < b.time;
	});

	string answer = "";
	for (int i = 0; i < keys.size(); ++i) {
		answer += keys[i].alp;
	}
	
	cout << answer << '\n';

	return 0;
}
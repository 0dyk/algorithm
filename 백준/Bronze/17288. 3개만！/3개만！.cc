#include<iostream>
#include<string>

using namespace std;

int main() {
	string str;
	cin >> str;

	int answer = 0;

	for (int i = 0; i < str.size() - 2;) {
		int cnt = 0;
		
		// idx 범위 내에서 연속되지 않을 때 까지
		while (i + cnt + 1 < str.size() &&
			str[i + cnt + 1] - str[i + cnt] == 1) {
			cnt++;
		}

		if (cnt == 2) {
			answer++;
		}

		i += cnt + 1;
	}

	cout << answer << '\n';

	return 0;
}
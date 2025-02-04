#include <iostream>
#include <string>

using namespace std;

int main() {

	string str;
	int count[5] = { 0, };

	int answer = 0;

	cin >> str;

	for (int i = 0; i < str.size(); ++i) {

		if (str[i] == 'q') {

			count[0]++;
		}
		else if (str[i] == 'u'){

			count[1]++;
		}
		else if (str[i] == 'a') {

			count[2]++;
		}
		else if (str[i] == 'c') {

			count[3]++;
		}
		else if (str[i] == 'k') {

			count[4]++;
		}

		if (count[0] < count[1] || count[1] < count[2] || count[2] < count[3] || count[3] < count[4]) {

			answer = -1;
			break;
		}

		if ((count[0] > 0) && (count[1] > 0) && (count[2] > 0) && (count[3] > 0) && (count[4] > 0)) {

			for (int j = 0; j < 5; ++j) count[j]--;
		}
		
		for (int j = 0; j < 5; ++j) {

			if (count[j] > answer) answer = count[j];
		}
	}

	if (count[0] || count[1] || count[2] || count[3] || count[4]) {

		answer = -1;
	}

	cout << answer << '\n';

	return 0;
}
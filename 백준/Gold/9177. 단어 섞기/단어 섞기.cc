#include<iostream>
#include<string>
using namespace std;

string str1, str2, str3;

bool dp[201][201];

bool res;

void solve(int i, int j, int k) {
	if (res || k == str3.length()) {
		res = true;
		return;
	}

	if (i < str1.length() && str1[i] == str3[k] && !dp[i + 1][j]) {
		dp[i + 1][j] = true;
		solve(i + 1, j, k + 1);
	}
	if (j < str2.length() && str2[j] == str3[k] && !dp[i][j + 1]) {
		dp[i][j + 1] = true;
		solve(i, j + 1, k + 1);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> str1 >> str2 >> str3;

		for (int i = 0; i <= str1.length(); ++i) {
			for (int j = 0; j <= str2.length(); ++j) {
				dp[i][j] = false;
			}
		}

		res = false;
		solve(0, 0, 0);

		if (res) cout << "Data set " << tc << ": yes\n";
		else cout << "Data set " << tc << ": no\n";
	}

	return 0;
}
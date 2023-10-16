#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int T; cin >> T;

	vector<string> v;

	int N, cnt, minDist; string str1, str2, tmp;
	for (int tc = 1; tc <= T; tc++) {
		int N; cin >> N;
		
		v.clear();
		minDist = 12;
		if (N >= 48) {
			for (int i = 0; i < N; i++) {
				cin >> tmp;
			}
			minDist = 0;
		}
		else {
			for (int i = 0; i < N; i++) {
				cin >> tmp;
				v.push_back(tmp);
			}

			for (int i = 0; i < v.size() - 2; i++) {
				for (int j = i + 1; j < v.size() - 1; j++) {
					for (int k = j + 1; k < v.size(); k++) {
						cnt = 0;

						for (int idx = 0; idx < 4; idx++) {
							if (v[i][idx] != v[j][idx]) ++cnt;
							if (v[i][idx] != v[k][idx]) ++cnt;
							if (v[j][idx] != v[k][idx]) ++cnt;
						}

						if (cnt < minDist) minDist = cnt;
					}
				}
			}
		}

		cout << minDist << '\n';
	}

	return 0;
}
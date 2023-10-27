#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;

vector<long long> v;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int tmp;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	long long res = 3000000001;
	int resArray[3] = {};

	// i : 용액1
	for (int i = 0; i < v.size() - 2; ++i) {

		// start : 용액2, end : 용액3
		int start = i + 1, end = v.size() - 1;

		// start < end

		// 값이 음수면 ++start
		// 값이 양수면 --end

		// 
		long long tmp = 3000000001;

		while (start != end) {
			// int -> long long에서 오류
			tmp = v[i] + v[start] + v[end];

			if (res > abs(tmp)) {
				res = abs(tmp);
				resArray[0] = v[i];
				resArray[1] = v[start];
				resArray[2] = v[end];
			}

			if (tmp < 0) ++start;
			else if (tmp > 0) --end;
			else break;
		}
	}

	cout << resArray[0] << ' ' << resArray[1] << ' ' << resArray[2] << '\n';

	return 0;
}
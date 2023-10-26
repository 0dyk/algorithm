#include <iostream>
#include <map>
using namespace std;

int arr[1001];
int prefixArr[1001];
map<long long, long long> mArr;

int brr[1001];
int prefixBrr[1001];
map<long long , long long> mBrr;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T, N, M;
	cin >> T;

	cin >> N;
	for (int i = 1; i <= N; ++i) { cin >> arr[i]; prefixArr[i] = prefixArr[i - 1] + arr[i]; }

	cin >> M;
	for (int i = 1; i <= M; ++i) { cin >> brr[i]; prefixBrr[i] = prefixBrr[i - 1] + brr[i]; }
	
	for (int i = N; i >= 1; --i) {
		for (int j = 0; j < i; ++j) {
			long long tmp = prefixArr[i] - prefixArr[j];

			if (!mArr.count(tmp)) mArr[tmp] = 1;
			else ++mArr[tmp];
		}
	}

	for (int i = M; i >= 1; --i) {
		for (int j = 0; j < i; ++j) {
			long long tmp = prefixBrr[i] - prefixBrr[j];

			if (!mBrr.count(tmp)) mBrr[tmp] = 1;
			else ++mBrr[tmp];
		}
	}

	long long res = 0;

	for (auto iter = mArr.begin(); iter != mArr.end(); ++iter) {
		long long value = (*iter).first;
		long long cnt = (*iter).second;

		long long tmp = T - value;

		if (mBrr.find(tmp) != mBrr.end()) {
			res += cnt * mBrr[tmp];
		}
	}

	cout << res << '\n';

	return 0;
}
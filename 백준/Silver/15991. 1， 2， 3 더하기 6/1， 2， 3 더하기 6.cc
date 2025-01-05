#include<iostream>
#include<vector>
using namespace std;

int sum[100001];

int main() {

	int N;
	cin >> N;

	sum[1] = 1; // 1
	sum[2] = 2; // 11, 2
	sum[3] = 2; // 111, 3
	sum[4] = 3; // 1111, 121, 22
	sum[5] = 3; // 11111, 131, 212
	sum[6] = 6; // 111111, 11211, 1221, 2112, 222, 33

	for (int i = 7; i < 100001; ++i) {

		sum[i] = ((long long)sum[i - 2] + sum[i - 4] + sum[i - 6]) % 1000000009;
	}

	int tmp;
	vector<int> input;
	for (int i = 0; i < N; ++i) {

		cin >> tmp;
		input.push_back(tmp);
	}

	for (int i = 0; i < input.size(); ++i) {

		cout << sum[input[i]] << '\n';
	}

	return 0;
}
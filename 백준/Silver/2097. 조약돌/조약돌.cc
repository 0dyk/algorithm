#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int N;
	cin >> N;

	int k = (int)sqrt(N);

	int answer = 0;
	
	if (N <= 4) {

		answer = 4;
	}
	else if (k * k >= N) {

		answer = 4 * (k - 1);
	}
	else if (k * (k + 1) >= N) {

		answer = 4 * (k - 1) + 2;
	}
	else {

		answer = 4 * (k - 1) + 4;
	}

	cout << answer << '\n';

	return 0;
}
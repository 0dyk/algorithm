#include <iostream>

using namespace std;

int main() {

	int H, W, N, M;

	cin >> H >> W >> N >> M;

	int tmp1 = H / (N + 1);
	if ((N + 1) * tmp1 + 1 <= H) {
		tmp1++;
	}

	int tmp2 = W / (M + 1);
	if ((M + 1) * tmp2 + 1 <= W) {
		tmp2++;
	}

	int answer = tmp1 * tmp2;

	cout << answer << '\n';

	return 0;
}
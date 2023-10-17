#include<iostream>

using namespace std;

int N;

bool isStar[3072][6143];

// x, y는 꼭짓점
void starOrBlank(int x, int y, int size) {
	if (size == 3) {
		isStar[x][y] = true;
		isStar[x + 1][y - 1] = true;
		isStar[x + 1][y + 1] = true;
		for (int i = y - 2; i <= y + 2; ++i)
			isStar[x + 2][i] = true;
		return;
	}

	// size가 3보다 크면 재귀
	// size / 2 만큼 좌우
	int tmp = size / 2;
	starOrBlank(x, y, tmp);
	starOrBlank(x + tmp, y - tmp, tmp);
	starOrBlank(x + tmp, y + tmp, tmp);
}

int main() {
	cin >> N;

	starOrBlank(0, N - 1, N);

	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N * 2 - 1; ++j) {
			if (isStar[i][j]) cout << '*';
			else cout << ' ';

			if (j == N * 2 - 2) cout << '\n';
		}
	}

	return 0;
}
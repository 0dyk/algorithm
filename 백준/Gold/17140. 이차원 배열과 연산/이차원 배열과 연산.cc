#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, k;
int answer;
int matrix[101][101];

int num_cnt[101];

int main() {

	// init
	answer = -1;

	// input
	cin >> r >> c >> k;
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			cin >> matrix[i][j];
		}
	}

	// 초기 값이 정답인 경우
	if (matrix[r][c] == k) {
		answer = 0;
	}
	// 연산 수행
	else {
		int time = 0;
		int row_size = 3, col_size = 3;

		while (time++ < 101) {
			// R 연산
			if (row_size >= col_size) {
				int max_col_size = 0;

				for (int i = 1; i <= row_size; i++) {
					for (int j = 0; j < 101; ++j) num_cnt[j] = 0;
					vector<pair<int, int>> tmp;

					for (int j = 1; j <= col_size; j++) {
						num_cnt[matrix[i][j]]++;
						matrix[i][j] = 0;
					}

					// 정렬
					// 1. 수의 등장 횟수가 작은거
					// 2. 수의 크기가 작은 거
					for (int j = 1; j < 101; j++) {
						if(num_cnt[j] != 0) tmp.push_back({num_cnt[j], j});
					}

					sort(tmp.begin(), tmp.end());
					
					// x가 10개 이상이 되는 경우가 있나...?
					int idx = 1;
					for (int j = 0; j < tmp.size(); j++) {
						matrix[i][idx++] = tmp[j].second;
						if (idx >= 100) break;
						matrix[i][idx++] = tmp[j].first;
						if (idx >= 100) break;
					}

					if (max_col_size < idx) max_col_size = idx;
				}

				col_size = max_col_size;
			}
			// C 연산
			else {
				int max_row_size = 0;

				for (int i = 1; i <= col_size; i++) {
					for (int j = 0; j < 101; ++j) num_cnt[j] = 0;
					vector<pair<int, int>> tmp;

					for (int j = 1; j <= row_size; j++) {
						num_cnt[matrix[j][i]]++;
						matrix[j][i] = 0;
					}

					for (int j = 1; j < 101; j++) {
						if (num_cnt[j] != 0) tmp.push_back({ num_cnt[j], j });
					}

					sort(tmp.begin(), tmp.end());

					if (max_row_size < tmp.size() * 2) max_row_size = tmp.size() * 2;

					int idx = 1;
					for (int j = 0; j < tmp.size(); j++) {
						matrix[idx++][i] = tmp[j].second;
						if (idx >= 100) break;
						matrix[idx++][i] = tmp[j].first;
						if (idx >= 100) break;
					}

					if (max_row_size < idx) max_row_size = idx;
				}

				row_size = max_row_size;
			}

			if (matrix[r][c] == k) {
				answer = time;
				break;
			}
		}
	}

	cout << answer << '\n';

	return 0;
}
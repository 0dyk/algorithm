#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int arr[1001][1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	char tmp;
	for(int i = 0; i < N; ++i){
		for(int j =0; j <M; ++j){
			cin >> tmp;
			if (tmp == '1') arr[i][j] = 1;
		}
	}

	int maxV = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (arr[i][j] == 0) continue;

			if (i > 0 && j > 0) {
				int t = min(arr[i - 1][j], arr[i][j - 1]);
				t = min(t, arr[i - 1][j - 1]);
				if (t != 0 && t + 1 > arr[i][j]) {
					arr[i][j] = t + 1;
				}
			}

			if (arr[i][j] > maxV) maxV = arr[i][j];
		}
	}
	
	cout << maxV * maxV << '\n';

	return 0;
}
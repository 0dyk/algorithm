#include<iostream>
using namespace std;

int arr[3], dist[2][3];

int maxV(int a, int b) {
	return a > b ? a : b;
}
int minV(int a, int b) {
	return a < b ? a : b;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[j];
		}
		int tmp[3];
		tmp[0] = maxV(dist[0][0] + arr[0], dist[0][1] + arr[0]);
		tmp[1] = maxV(maxV(dist[0][0] + arr[1], dist[0][1] + arr[1]), dist[0][2] + arr[1]);
		tmp[2] = maxV(dist[0][1] + arr[2], dist[0][2] + arr[2]);
		dist[0][0] = tmp[0];
		dist[0][1] = tmp[1];
		dist[0][2] = tmp[2];

		int ttmp[3];
		ttmp[0] = minV(dist[1][0] + arr[0], dist[1][1] + arr[0]);
		ttmp[1] = minV(minV(dist[1][0] + arr[1], dist[1][1] + arr[1]), dist[1][2] + arr[1]);
		ttmp[2] = minV(dist[1][1] + arr[2], dist[1][2] + arr[2]);
		dist[1][0] = ttmp[0];
		dist[1][1] = ttmp[1];
		dist[1][2] = ttmp[2];
	}

	int maxSum = maxV(maxV(dist[0][0], dist[0][1]), dist[0][2]);
	int minSum = minV(minV(dist[1][0], dist[1][1]), dist[1][2]);
	   
	cout << maxSum << ' ' << minSum << '\n';

	return 0;
}
#include<iostream>
using namespace std;

int N, C, maxDist;
int arr[200001];
int brr[200001];

/*
 * merge
 */
void merge(int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) brr[k++] = arr[i++];
		else brr[k++] = arr[j++];
	}

	int tmp = i > mid ? j : i;
	while (k <= right) brr[k++] = arr[tmp++];

	for (int i = left; i <= right; i++) arr[i] = brr[i];
}

/*
 * sort
 */
void mergeSort(int left, int right) {
	if (left < right) {
		int mid = (left + right) >> 1;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, mid, right);
	}
}

/*
 * mid값(dist)이 가능한지 확인
 */
bool check(int mid) {
	int cnt = 1;
	int prev = arr[1];
	for (int i = 2; i <= N; i++) {
		if (arr[i] - prev >= mid) {
			cnt++;
			prev = arr[i];
		}
	}
	if (cnt >= C) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cin.tie(NULL);
	cin >> N >> C;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	mergeSort(1, N);

	int left = 0;
	int right = arr[N];

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (check(mid)) {
			left = mid + 1;
			if (maxDist < mid)maxDist = mid;
		}
		else {
			right = mid - 1;
		}
	}

	cout << maxDist << '\n';

	return 0;
}
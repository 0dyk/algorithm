#include<iostream>
#define MAX_N 100100
using namespace std;

int N, M;
int arr[MAX_N];
int maxTree[MAX_N * 4];
int minTree[MAX_N * 4];

int maxv(int a, int b) {
	return (a > b) ? a : b;
}
int minv(int a, int b) {
	return (a <  b) ? a : b;
}

void makeSeg(int left, int right, int node) {
	if (left == right) {
		maxTree[node] = minTree[node] = arr[left];
		return;
	}
	int mid = (left + right) >> 1;
	makeSeg(left, mid, node << 1);
	makeSeg(mid + 1, right, node << 1 | 1);
	maxTree[node] = maxv(maxTree[node << 1], maxTree[node << 1 | 1]);
	minTree[node] = minv(minTree[node << 1], minTree[node << 1 | 1]);
	return;
}

pair<int, int> findMinMAx(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return make_pair(INT32_MAX, 0);
	}
	else if (left <= start && end <= right) {
		return make_pair(minTree[node], maxTree[node]);
	}
	else {
		pair<int, int> l, r;
		l = findMinMAx(node * 2, start, (start + end) / 2, left, right);
		r = findMinMAx(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
		return make_pair(min(l.first, r.first), max(l.second, r.second));
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (register int i = 1; i <= N; i++) cin >> arr[i];
	makeSeg(1, N, 1);

	for (register int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		pair<int, int> res = findMinMAx(1, 1, N, a, b);
		cout << res.first << ' ' << res.second << '\n';
	}

	return 0;
}
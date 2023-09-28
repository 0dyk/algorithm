#include<iostream>
#define MAX_N 1000001
using namespace std;
typedef long long ll;

int N, M, K;

ll arr[MAX_N];
ll tree[MAX_N * 4];
ll lazy[MAX_N * 4];

ll makeSeg(int left, int right, int node) {
	if (left == right) return tree[node] = arr[left];
	int mid = (left + right) / 2;
	return tree[node] = makeSeg(left, mid, node * 2) + makeSeg(mid + 1, right, node * 2 + 1);
}

void lazyUpdate(int left, int right, int node) {
	if (lazy[node] == 0) return;
	tree[node] += (right - left + 1) * lazy[node];
	if (left != right) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}

	lazy[node] = 0;
}

void update(int left, int right, int a, int b, int node, ll dif) {
	lazyUpdate(left, right, node);

	if (a > right || b < left) return;
	if (a <= left && b >= right) {
		tree[node] += (right-left+1)*dif;
		if (left != right) {
			lazy[node * 2] += dif;
			lazy[node * 2 + 1] += dif;
		}
		return;
	}

	int mid = (left + right) / 2;

	update(left, mid, a, b, node * 2, dif);
	update(mid + 1, right, a, b, node * 2 + 1, dif);
	
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

// 전체범위, 탐색범위, 노드
ll getSum(int left, int right, int a, int b, int node) {
	lazyUpdate(left, right, node);

	if (a > right || b < left) return 0;
	if (a <= left && b >= right) return tree[node];

	int mid = (left + right) / 2;

	return getSum(left, mid, a, b, node * 2) + getSum(mid + 1, right, a, b, node * 2 + 1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (register int i = 1; i <= N; i++) cin >> arr[i];
	makeSeg(1, N, 1);


	for (register int i = 0; i < M+K; i++) {
		int a, b, c; ll d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			update(1, N, b, c, 1, d);
		}
		else {
			cin >> b >> c;
			cout << getSum(1, N, b, c, 1) << '\n';
		}
	}

	return 0;
}
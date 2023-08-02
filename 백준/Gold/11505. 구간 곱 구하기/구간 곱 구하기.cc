#include<iostream>
#define MAX_N 1000001
#define NMZ 1000000007
using namespace std;
typedef long long ll;

int N, M, K;

ll arr[MAX_N];
ll tree[MAX_N * 4];

ll make_seg(int left, int right, int node) {
	if (left == right) return tree[node] = arr[left];
	int mid = (left + right) >> 1;
	return tree[node] = (make_seg(left, mid, node << 1) * make_seg(mid + 1, right, node << 1 | 1)) % NMZ;
}

void update(int left, int right, int node, int idx, ll dif) {
	if (idx < left || idx > right) return;

	// 바텀 업으로 업데이트하기
	if (left == right) {
		tree[node] = dif;
		return;
	}

	int mid = (left + right) >> 1;
	update(left, mid, node << 1, idx, dif);
	update(mid+1,right, node << 1|1, idx, dif);
	tree[node] = (tree[node << 1] * tree[node << 1 | 1]) % NMZ;
}

ll getSum(int left, int right, int a, int b, int node) {
	if (a > right || b < left) return 1;
	if (a <= left && b >= right) return tree[node];
	int mid = (left + right) >> 1;
	return (getSum(left, mid, a, b, node << 1) * getSum(mid + 1, right, a, b, node << 1 | 1)) % NMZ;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;

	for (register int i = 1; i <= N; i++) cin >> arr[i];
	make_seg(1, N, 1);

	for (register int i = 0; i < M + K; i++) {
		int a, b, c; ll d;
		cin >> a;
		if (a == 1) {
			cin >> b >> d;
			update(1, N, 1, b, d);
			arr[b] = d;
		}
		else {
			cin >> b >> c;
			cout << getSum(1, N, b, c, 1) << '\n';
		}
	}

	return 0;
}
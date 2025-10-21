#include<iostream>
#define MAX_N 1000001
using namespace std;
typedef long long ll;

int N, M, K, sz;
ll arr[MAX_N];

struct Node {
	ll value;
};

Node nodes[2097152 + 1];

ll init(int left, int right, int idx) {
	if (left == right) return nodes[idx].value = arr[left];
	int mid = (left + right) / 2;
	return nodes[idx].value = init(left, mid, idx * 2) + init(mid + 1, right, idx * 2 + 1);	
}

void update(int left, int right, int idx, int target, ll x) {
	if (target < left || target > right) return;
	nodes[idx].value += x;
	if (left != right) {
		int mid = (left + right) / 2;
		update(left, mid, idx * 2, target, x);
		update(mid + 1, right, idx * 2 + 1, target, x);
	}
}

// a ~ b까지 구하기
ll getSum(int left, int right, int a, int b, int idx) {
	if (b < left || right < a) return 0;
	if (a <= left && b >= right) return nodes[idx].value;
	int mid = (left + right) / 2;
	return getSum(left, mid, a, b, idx * 2) + getSum(mid+1, right, a, b, idx*2+1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (register int i = 1; i <= N; i++) cin >> arr[i];

	init(1, N, 1);

	int a, b, c; long long cc;
	for (register int i = 0; i < M + K; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b >> cc;
			update(1, N, 1, b, cc - arr[b]);
			arr[b] = cc;
		}
		else {
			cin >> b >> c;
			cout << getSum(1, N, b, c, 1) << '\n';
		}
	}

	return 0;
}
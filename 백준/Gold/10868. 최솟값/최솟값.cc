#include<iostream>
#include<algorithm>
#define INF 1111111111
#define mid ((left + right) >> 1)
#define lChild (node << 1)
#define rChild (node << 1 | 1)
using namespace std;

int N, M;
int arr[100001];
int tree[100001 * 4];

// left ~ right,  현재 노드 : node
int make_seg(int left, int right, int node) {
	if (left == right) return tree[node] = arr[left];
	return tree[node] = min(make_seg(left, mid, lChild), make_seg(mid + 1, right, rChild));
}

// left ~ right 범위에서 a ~ b 구간의 최소값 구하기, 현재 노드 : node
int get_min(int left, int right, int a, int b, int node) {
	if (a > right || b < left) return INF;
	if (a <= left && b >= right) return tree[node];
	return min(get_min(left, mid, a, b, lChild), get_min(mid+1, right, a, b, rChild));
}

// start ~ end 범위에서 idx번째 값을 data로 변경, 현재 노드 : node
void updates(int left, int right, int node, int idx, int data) {
	if (idx < left || idx > right) return;
	
	// 노드를 찾은 경우
	if (left == right) {
		tree[node] = data;
		return;
	}

	updates(left, mid, lChild, idx, data);
	updates(mid, right, rChild, idx, data);

	tree[node] = min(tree[lChild], tree[rChild]);
}



int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	make_seg(1, N, 1);

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << get_min(1, N, a, b, 1) << '\n';
	}

	return 0;
}
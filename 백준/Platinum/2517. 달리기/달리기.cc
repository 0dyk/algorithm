#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 500001
#define mid (left + right) / 2
#define lChild node * 2
#define rChild node * 2 + 1
using namespace std;

int N;

int pcnt[MAX_N];
vector<pair<int, int>> v;
int tree[MAX_N * 4];

// left ~ right, node
//int make_seg(int left, int right, int node) {
//	if (left == right) return tree[node] = 1;
//	return make_seg(left, mid, node * 2) + make_seg(mid + 1, right, node * 2 + 1);
//}

// left ~ right 범위에서 a ~ b까지의 합, node
int get_sum(int left,int right, int a, int b, int node) {
	// 구간을 벗어나면 영향을 끼치지 않는 값 리턴하기
	if (a > right || b < left) return 0;
	
	if (a <= left && b >= right) return tree[node];

	return get_sum(left, mid, a, b, lChild) + get_sum(mid + 1, right, a, b, rChild);
}

// left ~ right 구간에서 idx 값 + 1
void update(int left, int right, int idx, int node) {
	if (idx < left || idx > right) return;

	if (left == right) {
		tree[node]++;
		return;
	}

	update(left, mid, idx, lChild);
	update(mid + 1, right, idx, rChild);

	tree[node] = tree[lChild] + tree[rChild];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int a;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		// i번째 선수의 능력 a
		v.push_back({ a, i });
	}
	
	// 능력 순으로 정렬
	sort(v.begin(), v.end());

	// 능력이 가장 작은 사람 ~ 가장 큰 사람
	for (int i = 0; i < N; i++) {
		v[i].first = i + 1;
		int tmp = v[i].first;
		v[i].first = v[i].second;
		v[i].second = tmp;
	}

	// 구간합 트리 만들기
	// make_seg(1, N, 1);
	// 초기값 모두 0

	// 인덱스 순으로 정렬
	sort(v.begin(), v.end());

	// 첫번째 사람 ~ 마지막 사람
	for (int i = 0; i < v.size(); i++) {
		// 능력
		int av = v[i].second;

		// 능력이 av인 사람 1명 추가하기
		update(1, N, av, 1);

		// 현재 내 등수 - 나보다 능력이 낮은 사람 수
		cout << (i + 1) -get_sum(1, N, 1, av - 1, 1) << '\n';
	}

	return 0;
}
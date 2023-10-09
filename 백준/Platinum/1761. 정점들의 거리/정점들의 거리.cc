#include <iostream>
#include <vector>
#define MAXN 40001
using namespace std;

struct NODE {
	// 부모
	int par;

	// 깊이
	int depth;

	// 부모까지의 거리
	int cost;
};

// 부모, 비용
NODE tree[MAXN];

// 노드의 개수, 
int N, M;

// adj : a -> {b, cost}
vector<pair<int, int>> adj[MAXN];

// 현재 노드
void makeTree(int idx, int dep) {
	tree[idx].depth = dep;

	for (int i = 0; i < adj[idx].size(); i++) {
		// 방문하지 않은 정점일 경우
		if (tree[adj[idx][i].first].depth == 0) {
			tree[adj[idx][i].first].par = idx;
			tree[adj[idx][i].first].cost = adj[idx][i].second;

			makeTree(adj[idx][i].first, dep + 1);
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	int a, b, c;
	for (int i = 0; i < N - 1; i++) {
		// a와 b가 c의 비용으로 연결
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	// 트리 만들기
	makeTree(1, 1);

	cin >> M;
	for (int i = 0; i < M; i++) {
		// a와 b 사이의 거리 구하기
		cin >> a >> b;

		// 거리 합 초기화
		c = 0;

		// 같을 때 까지
		while (a != b) {

			// 깊이가 다를 경우
			while (tree[a].depth != tree[b].depth) {
				// 항상 b를 올리기
				if (tree[a].depth > tree[b].depth) swap(a, b);

				c += tree[b].cost;
				b = tree[b].par;
			}

			// 깊이가 같아져도 값이 다를 경우 한칸 올려주기
			if (a != b) {
				c += tree[a].cost;
				a = tree[a].par;
			}
		}

		cout << c << '\n';
	}

	return 0;
}
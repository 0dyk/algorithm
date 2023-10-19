#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 정점, 간선의 개수
int V, E;

// 부모 배열(kruskal)
int parent[10001];

// 간선 가중치 c, 연결된 놈 a, b
vector<pair<int, pair<int, int>>> adj;

// x의 부모 찾기
int finds(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = finds(parent[x]);
}

// a와 b 합체
bool unions(int a, int b) {
	int pa = finds(a);
	int pb = finds(b);

	if (pa == pb) return false;

	parent[pb] = pa;
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E;

	int a, b, c;
	for (int i = 0; i < E; ++i) {
		// a정점과 b정점이 가중치 c인 간선으로 연결
		cin >> a >> b >> c;
		adj.push_back({ c, {a, b} });
	}

	// 크루스칼

	// 1. 간선정렬 및 초기화
	sort(adj.begin(), adj.end());
	for (int i = 1; i <= V; ++i) parent[i] = i;

	// 2. 비용이 작은 간선부터 연결
	
	// 가중치
	int sum = 0;

	// 연결
	for (int i = 0; i < adj.size(); ++i) {
		// 연결되어있지 않은 경우 연결하기
		if (unions(adj[i].second.first, adj[i].second.second)) {
			sum += adj[i].first;
		}
	}

	cout << sum << '\n';

	return 0;
}
#include<iostream>
#include<vector>

using namespace std;

int N, M;

int parent[201];

void make() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
}

int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}

void union_find(int x, int y) {
	int px = find(x);
	int py = find(y);

	if (px != py) {
		parent[py] = px;
	}
}

int main() {
	cin >> N;
	cin >> M;

	make();

	int tmp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> tmp;
			if (tmp == 1) {
				union_find(i, j);
			}
		}
	}

	bool res = true;

	int k, now;
	cin >> k;
	now = find(k);
	for (int i = 0; i < M - 1; i++) {
		cin >> k;
		if (now != find(k)) {
			res = false;
			break;
		}
	}

	if (res) cout << "YES" << '\n';
	else cout << "NO" << '\n';

	return 0;
}
#include<iostream>

using namespace std;

int N, M;
int parent[500000];

void make() {
	for (int i = 0; i < N; i++) {
		parent[i] = -1;
	}
}

int find(int x) {
	if (parent[x] < 0) return x;
	else return parent[x] = find(parent[x]);
}

bool unions(int x, int y){
	int px = find(x);
	int py = find(y);

	if (px == py) return false;

	// px의 size가 더 크게 만들기 -> parent 값이 더 작다
	if (parent[px] > parent[py]) {
		swap(px, py);
	}

	parent[px] += parent[py];
	parent[py] = px;

	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	make();

	int res = 0;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		// 이미 합쳐져 있는 경우
		if (!unions(a, b)) {
			res = i;
			break;
		}
	}

	cout << res << '\n';

	return 0;
}
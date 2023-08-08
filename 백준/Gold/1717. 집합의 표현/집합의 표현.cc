#include<iostream>
#define MAX_N 1000001
using namespace std;

int N, M;
int parent[MAX_N];

/*
 * My Parent = Me
 */
void init() {
	for (int i = 0; i <= N; i++) parent[i] = -1;
}

/*
 * Find Parent
 * parent[x]에 넣어주기
 */
int find(int x) {
	if (parent[x] < 0) return x;
	else return parent[x] = find(parent[x]);
}

/*
 * a, b Union
 * a == b 일때 return
 * parent[a]와 parent[b]를 비교해야한다.
 */
void doUnion(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;
	
	if (parent[a] < parent[b]) {parent[a] += parent[b]; parent[b] = a;}
	else {parent[b] += parent[a]; parent[a] = b;}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	init();
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a;
		if (a == 0) {
			cin >> b >> c;
			doUnion(b, c);
		}
		else {
			cin >> b >> c;
			if (find(b) == find(c)) cout << "yes" << '\n';
			else cout << "no" << '\n';
		}
	}

	return 0;
}
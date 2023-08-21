#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int n, m, v;
int arr[1001][1001];
int visited[1001];
queue<int> q;



void dfs(int v) {
	visited[v] = 1;
	cout << v << ' ';
	
	for (int i = 1; i <= n; i++) {
		if (arr[v][i] == 1 && visited[i] == 0) {
			dfs(i);
		}
	}
}

void bfs(int v) {
	q.push(v);
	visited[v] = 1;
	cout << v << ' ';

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for(int i = 1; i <= n; i++) {
			if (arr[v][i] == 1 && visited[i] == 0) {
				q.push(i);
				visited[i] = 1;
				cout << i << ' ';
			}
		}
	}
}


int main() {
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		
		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	dfs(v);

	cout << '\n';

	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
	}

	bfs(v);

	return 0;
}
#include<iostream>
#include<map>
using namespace std;

int N;
map<string, pair<string, int>> parent;

string find(string a) {
	if (a == parent[a].first) return a;
	else return parent[a].first = find(parent[a].first);
}

int union_find(string a, string b) {
	string pa = find(a);
	string pb = find(b);

	if (pa != pb) {
		parent[pb].first = pa;
		parent[pa].second += parent[pb].second;
	}

	return parent[pa].second;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		parent.clear();

		for (int i = 0; i < N; i++) {
			string a, b;
			cin >> a >> b;
			if (!parent.count(a)) parent[a] = { a, 1 };
			if (!parent.count(b)) parent[b] = { b,1 };

			cout << union_find(a, b) << '\n';
		}
	}

	return 0;
}
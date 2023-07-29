#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int n, m, sz;
vector<pair<ll, ll>> v;	// min, max


void update(int pos, ll x) {
	int idx = sz + pos - 1;
	while (idx) {
		v[idx].first = min(v[idx].first, x);
		v[idx].second = max(v[idx].second, x);
		idx /= 2;
	}
}

ll min_search(int pos, int left, int right, int start, int end) {
	if (left > end || right < start) return 1e10;
	if (left <= start && end <= right) return v[pos].first;

	int mid = (start + end) / 2;
	return min(min_search(pos * 2, left, right, start, mid), min_search(pos * 2 + 1, left, right, mid + 1, end));
}

ll max_search(int pos, int left, int right, int start, int end) {
	if (left > end || right < start) return -1;
	if (left <= start && end <= right) return v[pos].second;

	int mid = (start + end) / 2;
	return max(max_search(pos * 2, left, right, start, mid), max_search(pos * 2 + 1, left, right, mid + 1, end));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	sz = 1;	while (sz < n) sz *= 2;
	v.resize(sz * 2);
	for (int i = 1; i < v.size(); i++) {
		v[i] = {1e10, -1};
	}

	/*init*/
	for (int i = 1; i <= n; i++) {
		ll x; cin >> x;
		update(i, x);
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cout << min_search(1, x, y, 1, sz) << ' ' << max_search(1, x, y, 1, sz) << '\n';
	}

	return 0;
}
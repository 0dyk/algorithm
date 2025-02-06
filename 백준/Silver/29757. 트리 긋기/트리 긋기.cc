#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	// N개의 점
	int N;
	cin >> N;

	vector<pair<pair<int, int>, int>> v;
	vector<pair<int, int>> answer;

	for (int i = 0; i < N; ++i) {

		int x, y;
		cin >> x >> y;

		v.push_back({ { x,y } , i + 1});
	}
	
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size() - 1; ++i) {
		
		answer.push_back({v[i].second, v[i+1].second});
	}

	for (int i = 0; i < answer.size(); ++i) {

		cout << answer[i].first << " " << answer[i].second << '\n';
	}

	return 0;
}
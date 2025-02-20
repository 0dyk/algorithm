#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<long long, pair<int, int>> zeroCoordinate;

int main() {

	int N;
	cin >> N;

	long long x, y;
	for (int i = 0; i < N; ++i) {
		
		cin >> x >> y;

		// 기울기 1
		zeroCoordinate[x - y].first++;

		// 기울기 -1
		zeroCoordinate[x + y].second++;
	}

	long long answer = zeroCoordinate.size();

	int plusCount = 0;
	int minusCount = 0;

	for (auto iter = zeroCoordinate.begin(); iter != zeroCoordinate.end(); ++iter) {
		
		if ((*iter).second.second > 0) {
			answer += plusCount;
		}

		if ((*iter).second.first > 0) plusCount++;
	}

	cout << answer << '\n';

	return 0;
}
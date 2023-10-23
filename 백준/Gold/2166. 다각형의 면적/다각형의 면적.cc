#include<iostream>
#include<vector>
using namespace std;

// 점 개수
int N;

// 정답
double res;

// x, y 좌표
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int x, y;
	for (int i = 0; i < N; ++i) {
		cin >> x >> y;
		v.push_back({ x, y });
	}

	x = v[0].first;
	y = v[0].second;

	for (int i = 1; i < v.size() - 1; ++i) {
		// x,y와 i, i+1의 넓이 구하기
		double x1 = v[i].first;
		double y1 = v[i].second;
		double x2 = v[i + 1].first;
		double y2 = v[i + 1].second;
		// 3점의 좌표를 이용하여 삼각형의 넓이 구하기
		double tmp = (x * y1 + x1 * y2 + x2 * y) - (x1 * y + x2 * y1 + x * y2);
		tmp /= 2;
		
		res += tmp;
	}

	cout << fixed;
	cout.precision(1);
	cout << abs(res) << '\n';

	return 0;
}
#include<iostream>
#include<set>
#include<string>
#include<tuple>
#define MAXN 100001
#define MAXP 1000000001
using namespace std;
typedef tuple<int,int,int> ti;

int N, K;
string dirstr;
//  \와 / 두개를 만들어서 관리?

// (x, y) 좌표  //  연결 리스트

set<ti> rightDown;
set<ti> rightUp;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	cin >> dirstr;


	int cx, cy;
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		if (i == 0) { cx = x; cy = y; };
		// RD 는 x + y 우선 순위
		rightDown.insert({ x - y,x, y });

		// RU 는 -x + y 우선 순위
		rightUp.insert({ x + y, x, y });
	}

	int sz = dirstr.length();

	for (int i = 0; i < sz; i++) {
		// RD 큰놈
		if (dirstr[i] == 'A') {
			// 다음 위치 탐색
			auto iter = rightDown.find({ cx - cy, cx, cy });

			// 다음 값이 존재 하지 않으면 패스
			if (iter == (--rightDown.end())) continue;

			int val, nx, ny;
			tie(val, nx, ny) = *(++iter);

			// 일치하는 값이 아닌 경우 패스
			if (val != cx - cy) continue;		

			// 해당 값 삭제
			rightDown.erase({ cx - cy, cx, cy });
			rightUp.erase({ cx + cy, cx, cy });

			// 이동
			cx = nx; cy = ny;
		}
		// RU 작은놈
		else if (dirstr[i] == 'B') {
			// 다음 위치 탐색
			auto iter = rightUp.find({ cx + cy, cx, cy });

			// 
			if (iter == rightUp.end()) continue;

			int val, nx, ny;
			tie(val, nx, ny) = *(++iter);

			// 일치하는 값이 아닌 경우 패스
			if (val != cx + cy) continue;

			// 해당 값 삭제
			rightDown.erase({ cx - cy, cx, cy });
			rightUp.erase({ cx + cy, cx, cy });

			// 이동
			cx = nx; cy = ny;
		}
		// RU 큰놈
		else if (dirstr[i] == 'C') {
			// 다음 위치 탐색
			auto iter = rightUp.find({ cx + cy, cx, cy });

			if (iter == rightUp.begin()) continue;

			int val, nx, ny;
			tie(val, nx, ny) = *(--iter);

			// 일치하는 값이 아닌 경우 패스
			if (val != cx + cy) continue;

			// 해당 값 삭제
			rightDown.erase({ cx - cy, cx, cy });
			rightUp.erase({ cx + cy, cx, cy });

			// 이동
			cx = nx; cy = ny;
		}
		// RD 작은놈
		else if (dirstr[i] == 'D') {
			// 다음 위치 탐색
			auto iter = rightDown.find({ cx - cy, cx, cy });

			// 이전 값이 존재 하지 않으면 패스
			if (iter == rightDown.begin()) continue;

			int val, nx, ny;
			tie(val, nx, ny) = *(--iter);

			// 일치하는 값이 아닌 경우 패스
			if (val != cx - cy) continue;

			// 해당 값 삭제
			rightDown.erase({ cx - cy, cx, cy });
			rightUp.erase({ cx + cy, cx, cy });

			// 이동
			cx = nx; cy = ny;
		}
	}

	cout << cx << ' ' << cy << '\n';

	return 0;
}
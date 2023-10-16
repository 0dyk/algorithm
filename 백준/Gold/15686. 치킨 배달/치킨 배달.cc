#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

int N, M;

int minDist;

// 1 : 집, 2 : 치킨집, 3 : 선택된 치킨집
int arr[51][51];

// 집 좌표
vector<pair<int, int>> home;

// 치킨 집 좌표
vector<pair<int, int>> v;

vector<int> order;

// 방문 배열
bool visited[51][51];

// 모든 1들 탐색
void check() {
	int dist = 0;
	for (int i = 0; i < home.size(); i++) {
		// 초기화
		int d = 1987654321;
		for (int j = 0; j < M; j++) {
			int tmp = abs(home[i].first - v[order[j]].first) + abs(home[i].second - v[order[j]].second);
			if (tmp < d) d = tmp;
		}

		dist += d;
	}
	
	if (dist < minDist) minDist = dist;
}

// cnt개 뽑았어요
void combi(int start, int cnt) {
	if (cnt == M) {
		check();
		return;
	}

	for (int i = start; i < v.size(); ++i) {
		// v[i] 치킨 집 선택
		order.push_back(i);
		combi(i + 1, cnt + 1);
		order.pop_back();
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				home.push_back({ i,j });
			}
			else if (arr[i][j] == 2) {
				v.push_back({i, j});
			}
		}
	}

	minDist = 1987654321;
	combi(0, 0);

	cout << minDist << '\n';

	return 0;
}
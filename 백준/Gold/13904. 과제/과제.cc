#include<iostream>
#include<queue>
using namespace std;



struct NODE {
	int day;
	int score;

	NODE() {}
	NODE(int day, int score) : day(day), score(score) {}
};

// 점수가 높은 순
// 점수가 같을 경우 마감 시간이 늦은 순
struct comp {
	bool operator()(const NODE &a, const  NODE &b) {
		if(a.score != b.score) return a.score < b.score;
		return a.day < b.day;
	}
};


// 과제 수
int N;
int nodeCnt;
NODE nodes[1001];

int visited[1001];

priority_queue<NODE, vector<NODE>, comp> pq;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int d, w;
		cin >> d >> w;

		// d : 남은 일수, w : 과제 점수
		nodes[nodeCnt] = { d, w };

		pq.push(nodes[nodeCnt++]);
	}

	int res = 0;

	while (!pq.empty()) {
		int day = pq.top().day;
		int score = pq.top().score;
		pq.pop();

		for (int i = day; i >= 1; i--) {
			if (!visited[i]) {
				visited[i] = true;
				res += score;
				break;
			}
		}
	}

	cout << res << '\n';

	return 0;
}


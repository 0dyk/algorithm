#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 자식들을 저장한 배열
vector<int> v[101];

// 현재 가리키고 있는 자식
int curIdx[101];

int nowCnt[101];
int minCnt[101];
int maxCnt[101];

// 체크해야하는 친구들의 개수
int cnt = 0;

vector<int> order;

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;

    for (int i = 0; i < edges.size(); ++i) {
        v[edges[i][0]].push_back(edges[i][1]);
    }

    // 정렬
    for (int i = 1; i < 101; ++i) {
        sort(v[i].begin(), v[i].end());
    }

    // target 확인
    for (int i = 0; i < target.size(); ++i) {
        // 값을 저장해야하는 친구들
        if (target[i] != 0) {
            ++cnt;

            // 최대로 넣을 수 있는 개수
            maxCnt[i + 1] = target[i];

            // 최소로 넣을 수 있는 개수
            if (target[i] % 3) {
                minCnt[i + 1] += target[i] / 3 + 1;
            }
            else {
                minCnt[i + 1] += target[i] / 3;
            }
        }
    }

    // 값 탐색하기
    int now = 1;

    // 현재 추가하는 값 찾기 -> 리프 노드 찾기
    while (true) {

        // 자식이 없을 때 까지 탐색
        while (v[now].size() != 0) {
            // 가리키는 인덱스가 범위 초과시 0으로 이동
            if (curIdx[now] == v[now].size()) curIdx[now] = 0;

            // 다음 값 이동 및, 다음 인덱스 가리키기
            now = v[now][curIdx[now]++];

        }

        // now -> 현재 값을 추가해야 하는 리프 노드
        order.push_back(now);
        int t = ++nowCnt[now];

        if (t >= minCnt[now]) {
            // 이거 이제 가능해
            --cnt;

            // 중복체크 안되도록
            minCnt[now] = 1000;
        }
        // 나 더 못 먹어...
        else if (t > maxCnt[now]) {
            return { -1 };
        }

        // 우리 만들 수 잇어요~
        if (cnt == 0) {
            break;
        }

        now = 1;
    }

    // 만들어 보자~
    for (int i = 0; i < order.size(); i++) {
        // nowCnt[cnt] 번만에 target[order[i]]를 만들어야함
        int v = target[order[i] - 1];
        int c = nowCnt[order[i]]--;

        // v 를 c번만에 만드는데 

        if (c == 1) {
            answer.push_back(v);
            target[order[i] - 1] = 0;
        }
        else {
            // 1을 넣을 수 있나? 
            // v-1을 c-1회만에 만들 수 있는지 체크
            if ((v - 1 >= c - 1) && (v - 1 <= (c - 1) * 3)) {
                target[order[i] - 1] -= 1;
                answer.push_back(1);
            }
            // 2를 넣을 수 있나?
            // v-2를 c-1회만에 만들 수 있는지 체크
            else if ((v - 2 >= c - 1) && (v - 2 <= (c - 1) * 3)) {
                target[order[i] - 1] -= 2;
                answer.push_back(2);
            }
            // 3을 넣을 수 있나?
            // v-3를 c-1회만에 만들 수 있는지 체크
            else {
                target[order[i] - 1] -= 3;
                answer.push_back(3);
            }
        }
    }


    return answer;
}
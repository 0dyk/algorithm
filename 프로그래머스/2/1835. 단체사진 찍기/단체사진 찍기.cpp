#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node
{
    int nx;
    int pm;
    int val;
};

// now = {next, 부등호, 값}
vector<node> adj[26];

int answer;

// 방문 체크
bool visited[26];

// 0~7 -> A~T
int idx[8] = { 0,2,5,9,12,13,17,19 };

int order[26];

int abs(int k) {
    if (k > 0) return k;
    else return -k;
}

void solve(int cnt) {
    if (cnt == 8) {
        answer++;
        return;
    }

    // cnt 자리에 착석
    // 0 ~ 7 : A ~ T
    for (int i = 0; i < 8; ++i) {
        int now = idx[i];

        // 이미 체크한 알파벳이면 pass
        if (visited[now]) continue;

        // 착석 가능 여부
        bool isCan = true;

        // 불만족이 없는지 확인
        for (int j = 0; j < adj[now].size(); ++j) {
            // 상대방 next
            int nx = adj[now][j].nx;
            // 관계
            int pm = adj[now][j].pm;
            // 값 
            int val = adj[now][j].val;

            // 아직 줄을 서지 않은 친구면 pass
            if (!visited[nx]) continue;

            int dist = abs(cnt - order[nx]) - 1;
            
            // 
            if (pm == 0 && dist != val) {
                isCan = false;
                break;
            }
            if (pm == 1 && dist <= val) {
                isCan = false;
                break;
            }
            if (pm == -1 && dist >= val) {
                isCan = false;
                break;
            }
        }

        // 처리가 가능하다면
        if (isCan) {
            // 방문, 위치 처리
            visited[now] = true;
            order[now] = cnt;

            solve(cnt + 1);

            // 백트래킹
            visited[now] = false;
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    answer = 0;
    
    for (int i = 0; i < 26; ++i) {
        visited[i] = false;
        order[i] = 0;
        adj[i].clear();
    }
    idx[0] = 0;
    idx[1] = 2;
    idx[2] = 5;
    idx[3] = 9;
    idx[4] = 12;
    idx[5] = 13;
    idx[6] = 17;
    idx[7] = 19;
    
    
    // 간선 그래프
    for (int i = 0; i < data.size(); ++i) {
        // char to int
        int a = data[i][0] - 'A';
        int b = data[i][2] - 'A';
        int v = data[i][4] - '0';

        if (data[i][3] == '=') {
            adj[a].push_back({ b, 0, v });
            adj[b].push_back({ a, 0, v });
        }
        else if (data[i][3] == '>') {
            adj[a].push_back({ b, 1, v });
            adj[b].push_back({ a, 1, v });
        }
        else {
            adj[a].push_back({ b, -1, v });
            adj[b].push_back({ a, -1, v });
        }
    }

    solve(0);
    // 8명이 줄을 선다.

    return answer;
}
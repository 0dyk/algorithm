#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
bool isConnect[101][101];
bool visited[101];

// 몇 개의 노트가 연결되어 있는지
int bfs(int k){
    int cnt = 0;
    
    queue<int> q;
    q.push(k);
    visited[k] = true;
    
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        cnt++;
        
        for(int i = 1; i <= N; ++i){
            // 방문하지 않았고, 연결되어 있는 경우
            if(!visited[i] && isConnect[tmp][i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    N = n;
    int answer = -1;
    
    // wires를 간선 배열로 변경하기
    for(int i = 0; i < wires.size(); ++i){
        isConnect[wires[i][0]][wires[i][1]] = true;
        isConnect[wires[i][1]][wires[i][0]] = true;
    }
    
    // 모든 와이어 끊기 (MAX : 99개)
    for(int i = 0; i < wires.size(); ++i){
        // 와이어 끊기
        isConnect[wires[i][0]][wires[i][1]] = false;
        isConnect[wires[i][1]][wires[i][0]] = false;
        
        // 초기화
        for(int j = 1; j <= n; ++j) visited[j] = false;
        
        int left = bfs(wires[i][0]);
        int right = bfs(wires[i][1]);
        
        int def = abs(left - right);
        
        if (answer == -1 || def < answer) {
            answer = def;
        }
        
        // 와이어 다시 연결
        isConnect[wires[i][0]][wires[i][1]] = true;
        isConnect[wires[i][1]][wires[i][0]] = true;
    }
    
    return answer;
}
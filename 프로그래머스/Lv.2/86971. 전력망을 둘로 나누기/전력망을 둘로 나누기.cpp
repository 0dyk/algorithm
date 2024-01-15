#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[101];
bool visited[101];

// a점과 연결된 개수 리턴
int bfs(int a){
    int res = 0;
    
    queue<int> q;
    q.push(a);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i = 0; i < adj[cur].size(); ++i){
            int next = adj[cur][i];
            
            if(visited[next]) continue;
            
            visited[next] = true;
            q.push(next);
            res++;
        }
    }
    
    return res;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    // 간선 리스트
    for(int i = 0; i < wires.size(); ++i){
        adj[wires[i][0]].push_back(wires[i][1]);
        adj[wires[i][1]].push_back(wires[i][0]);
    }
    
    // 모든 와이어 끊어보기
    for(int i = 0; i < wires.size(); ++i){
        // 방문배열 초기화
        for(int i = 1; i <= n; ++i) visited[i] = false;
        
        visited[wires[i][0]] = true;
        visited[wires[i][1]] = true;
        
        int dif = bfs(wires[i][0]) - bfs(wires[i][1]);
        if(dif < 0) dif *= -1;
        
        if(dif < answer) answer = dif;
    }
    
    return answer;
}
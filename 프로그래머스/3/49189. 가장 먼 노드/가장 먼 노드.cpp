#include <string>
#include <vector>
#include <queue>

using namespace std;

int dist[20001];

vector<int> adj[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    // 간선 연결 리스트
    for(int i = 0; i < edge.size(); ++i){
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    
    // 초기화
    for(int i = 0; i < 20001; ++i) dist[i] = -1;
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    int max_dist = 0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        if(dist[cur] > max_dist) max_dist = dist[cur];
        
        for(int i = 0; i < adj[cur].size(); ++i) {
            int next = adj[cur][i];
            if(dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    
    for(int i = 1; i <= n; ++i){
        if(dist[i] == max_dist) answer++;
    }
    
    return answer;
}
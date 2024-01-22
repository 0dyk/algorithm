#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int inDegree[1000001];
int outDegree[1000001];
bool visited[1000001];

vector<int> adj[1000001];

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    // 제일 큰 번호
    int N = 0;
    
    // 간선 체크
    for(int i = 0; i < edges.size(); ++i){
        inDegree[edges[i][1]]++;
        outDegree[edges[i][0]]++;
        
        // 가장 큰 번호 체크
        if(edges[i][0] > N) N = edges[i][0];
        if(edges[i][1] > N) N = edges[i][1];
        
        // 간선 리스트
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    
    int newPoint = 0;
    for(int i = 1; i <= N; ++i){
        if(outDegree[i] >= 2 && inDegree[i] == 0){
            newPoint = i;
            break;
        }
    }
    
    int donut = 0, stick = 0, eight = 0;
    
    // 새로 생긴 점에서 출발해서 탐색
    for(int i = 0; i < adj[newPoint].size(); ++i){
        // 점의 개수와 간선의 개수를 체크하자
        int start = adj[newPoint][i];
        
        queue<int> q;
        
        q.push(start);
        visited[start] = true;
        
        int pCnt = 1; int lCnt = 0;
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            for(int i = 0; i < adj[cur].size(); ++i){
                lCnt++;
                
                int next = adj[cur][i];
                if(!visited[next]){
                    visited[next] = true;
                    pCnt++;
                    q.push(next);
                }
            }
        }
        
        if(pCnt == lCnt) donut++;
        else if(pCnt == lCnt + 1) stick++;
        else if(pCnt == lCnt - 1) eight++;
    }
    
    answer.push_back(newPoint);
    answer.push_back(donut);
    answer.push_back(stick);
    answer.push_back(eight);
    
    return answer;
}

    // 단방향 그래프
    
    // 도넛 - 사이클
    
    // 막대 - 사이클인데 간선 1개 없음
    
    // n + 1 사이클 두개 / 1점 공유
    
    // 새로 생긴 친구
    // 자기한테 들어오는 게 1개도 없고
    // 나가는게 2개 이상
    
    // 빼고 탐색하기
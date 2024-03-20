#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<pair<int,int>> adjList[50001];

int check[50001];
int dist[50001];
int visited[50001];

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;

    for(int i = 0; i < gates.size(); ++i){
        check[gates[i]] = 1;
    }
    for(int i = 0; i < summits.size(); ++i){
        check[summits[i]] = 2;
    }
    
    // N, 간선 추가
    N = n;
    for(int i = 0; i < paths.size(); ++i){
        adjList[paths[i][0]].push_back({paths[i][1], paths[i][2]});
        adjList[paths[i][1]].push_back({paths[i][0], paths[i][2]});
    }
    
    int minDist = 2100000000;
    int start = 50002, end = 0;
    
    for(int i = 0; i < gates.size(); ++i){
        int gate = gates[i];
        
        priority_queue<pair<int,int>> pq;
        
        pq.push({0, gate});
        
        visited[gate] = gate;
        dist[gate] = 0;
        
        // cout << "게이트 탐색 : " << gate << '\n';
        
        while(!pq.empty()){
            int d = -pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            
            if(d > minDist) continue;
            
            if(check[cur] == 2){
                if(d < minDist) {
                    minDist = d;
                    start = gate;
                    end = cur;
                }else if(d == minDist && cur < end){
                    start = gate;
                    end = cur;
                }
                
                continue;
            }
        
            
            for(int j = 0; j < adjList[cur].size(); ++j) {
                int nx = adjList[cur][j].first;
                int nd = max(d, adjList[cur][j].second);
                
                if(check[nx] == 1) continue;
                if(visited[nx] == gate && dist[nx] <= nd) continue;
                
                visited[nx] = gate;
                dist[nx] = nd;
                
                pq.push({-nd, nx});
                // cout << nx << " " << nd << '\n';
            }
        }
    }

    answer.push_back(end);
    answer.push_back(minDist);
    
    return answer;
}
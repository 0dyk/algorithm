#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[201];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; ++i){
        if(visited[i]) continue;
        
        answer++;
        queue<int> q;
        q.push(i);
        visited[i] = true;
        
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            
            for(int j = 0; j < n; ++j){
                if(visited[j] || !computers[tmp][j]) continue;
                visited[j] = true;
                q.push(j);
            }
        }
    }
    
    return answer;
}
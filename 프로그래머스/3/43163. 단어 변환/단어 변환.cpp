#include <string>
#include <vector>
#include <queue>

using namespace std;

bool adj[52][52];
bool visited[52];

int solution(string begin, string target, vector<string> words) {
    
    int answer = 0;
    int word_length = begin.size();
    int N = words.size() + 1;
    
    int target_idx = -1;
    
    words.push_back(begin);
    
    for(int i = 0; i < words.size() - 1; ++i){
        if (target == words[i]){
            target_idx = i;
        }
            
        for(int j = i + 1; j < words.size(); ++j){
            int tmp = 0;
            
            for(int k = 0; k < word_length; ++k){
                if(words[i][k] == words[j][k]) tmp++;
            }
            
            if(tmp == word_length - 1) {
                adj[i][j] = true;
                adj[j][i] = true;
            }
        }
    }
    
    queue<pair<int, int>> q;
    q.push({N - 1, 0});
    visited[N - 1] = true;
    
    if(target_idx == -1) return 0;
    
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(cur == target_idx) {
            answer = cnt;
            break;
        }
        
        for(int i = 0; i < N; ++i){
            if(visited[i] || !adj[cur][i]) continue;
            
            visited[i] = true;
            q.push({i, cnt + 1});
        }
    }
    
    return answer;
}
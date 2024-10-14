#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer;

void permu(vector<vector<int>>& dungeons, bool visited[], int k, int cnt){
    if(cnt > answer) answer = cnt;
    
    for(int i = 0; i < dungeons.size(); ++i){
        if(visited[i] == true || k < dungeons[i][0]) continue;
        
        visited[i] = true;
        permu(dungeons, visited, k - dungeons[i][1], cnt + 1);
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    answer = 0;
    bool visited[8] = { false };
    
    permu(dungeons, visited, k, 0);
    
    return answer;
}
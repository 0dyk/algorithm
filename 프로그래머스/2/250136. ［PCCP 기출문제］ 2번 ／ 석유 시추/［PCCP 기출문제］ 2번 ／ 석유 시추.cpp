#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int prefix[505];

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    int N = land.size();
    int M = land[0].size();
    
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(land[i][j] == 0) continue;
            land[i][j] = 0;
            
            // 방문 안한 석유일 경우 탐색
            int left = j, right = j;
            
            queue<pair<int,int>> q;
            q.push({i, j});
         
            int cnt = 1;
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int k = 0; k < 4; ++k){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    
                    if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if(land[nx][ny] == 0) continue;
                    land[nx][ny] = 0;
                    
                    ++cnt;
                    q.push({nx,ny});
                    
                    if(ny < left) left = ny;
                    if(ny > right) right = ny;
                }
            }
            prefix[left] += cnt;
            prefix[right + 1] -= cnt;            
            
            // cout << left << " : " << right << " : " << cnt << '\n';
        }
    }
    
    int tmp = 0;
    for(int i = 0; i < M; ++i){
        tmp += prefix[i];
        if(tmp > answer) answer = tmp;
        
        // cout << tmp << '\n';
    }
    
    return answer;
}
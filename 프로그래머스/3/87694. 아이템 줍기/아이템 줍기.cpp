#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct INFO{
    int x, y, dist;
};

bool maps[102][102];
bool visited[102][102];

// 좌 상 우 하
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    // 테두리 칠하기
    for(int i = 0; i < rectangle.size(); ++i){
        for(int j = rectangle[i][0] * 2; j <= rectangle[i][2] * 2; ++j){
            for(int k = rectangle[i][1] * 2; k <= rectangle[i][3] * 2; ++k){
                maps[j][k] = true;
            }
        }
    }
    
    // 속 파먹기
    for(int i = 0; i < rectangle.size(); ++i){
        for(int j = rectangle[i][0] * 2 + 1; j < rectangle[i][2] * 2; ++j){
            for(int k = rectangle[i][1] * 2 + 1; k < rectangle[i][3] * 2; ++k){
                maps[j][k] = false;
            }
        }
    }

    queue<INFO> q;
    q.push({characterX, characterY, 0});
    visited[characterX][characterY] = true;
    
    while(!q.empty()){
        INFO cur = q.front();
        q.pop();
        
        if(cur.x == itemX && cur.y == itemY){
            answer = cur.dist;
            break;
        }
        
        for(int i = 0; i < 4; ++i){
            int nx = cur.x + dx[i]; int ny = cur.y + dy[i];
            int nnx = nx + dx[i]; int nny = ny + dy[i];
            
            if(nnx < 0 || nnx >= 102 || nny < 0 || nny >= 102) continue;
            if(visited[nnx][nny] || !maps[nx][ny]) continue;
            
            visited[nnx][nny] = true;
            q.push({nnx,nny, cur.dist + 1});
        }
    }
    
    return answer;
}
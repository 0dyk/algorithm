#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1턴에 경우의 수 : 16
// 최대 16턴 -> 256
int answer;
int N, M;

bool finished_red;
bool finished_blue;

bool visited[4][4][2];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int cnt, int rx, int ry, int bx, int by, vector<vector<int>> maze){
    // cout << rx << " " << ry << " | " << bx << " " << by << '\n';
    
    if(finished_red && finished_blue){
        if(cnt < answer || answer == 0){
            answer = cnt;
        }
        return;
    }
    
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            int nrx = rx;
            int nry = ry;
            
            int nbx = bx;
            int nby = by;
            
            if(!finished_red){
                nrx += dx[i];
                nry += dy[i];
            }
            if(!finished_blue){
                nbx += dx[j];
                nby += dy[j];
            }
            
            // 범위
            if(nrx < 0 || nrx >= N || nry < 0 || nry >= M) continue;
            if(nbx < 0 || nbx >= N || nby < 0 || nby >= M) continue;
            
            // 벽
            if(maze[nrx][nry] == 5 || maze[nbx][nby] == 5) continue;

            // 방문
            if(!finished_red && visited[nrx][nry][0]) continue;
            if(!finished_blue && visited[nbx][nby][1]) continue;

            // 같은 위치
            if(nrx == nbx && nry == nby) continue;

            // 교차
            if(nrx == bx && nry == by && rx == nbx && ry == nby) continue;

            if(maze[nrx][nry] == 3) finished_red = true;
            if(maze[nbx][nby] == 4) finished_blue = true;
            
            visited[nrx][nry][0] = true;
            visited[nbx][nby][1] = true;
            
            // 백트래킹 이동
            dfs(cnt + 1, nrx, nry, nbx, nby, maze);
            
            if(maze[nrx][nry] == 3) finished_red = false;
            if(maze[nbx][nby] == 4) finished_blue = false;
            
            visited[nrx][nry][0] = false;
            visited[nbx][nby][1] = false;
        }
    }
}

int solution(vector<vector<int>> maze) {
    answer = 0;
    N = maze.size();
    M = maze[0].size();
    
    int rx, ry, bx, by;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(maze[i][j] == 1){
                rx = i; ry = j;
                visited[rx][ry][0] = true;
                maze[i][j] = 0;
            }else if(maze[i][j] == 2){
                bx = i; by = j;
                visited[bx][by][1] = true;
                maze[i][j] = 0;
            }
        }
    }
    
    dfs(0, rx, ry, bx, by, maze);
    
    return answer;
}
#include<vector>
#include<queue>

using namespace std;

struct ROR{
    int x, y, cnt;
    // ROR(int x, int y, int cnt) : x(x), y(y), cnt(cnt) {}
};

int answer;
int N, M;
bool visited[101][101];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int solution(vector<vector<int>> maps)
{
    answer = -1;
    N = maps.size();
    M = maps[0].size();
    
    queue<ROR> q;
    q.push({0, 0, 1});
    visited[0][0] = true;
    
    while(!q.empty()){
        ROR tmp = q.front();
        q.pop();
        
        if(tmp.x == N - 1 && tmp.y == M - 1){
            answer = tmp.cnt;
            break;
        }
        
        for(int i = 0; i < 4; ++i){
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(maps[nx][ny] == 0 || visited[nx][ny]) continue;
        
            visited[nx][ny] = true;
            q.push({nx, ny, tmp.cnt + 1});
        }
    }
    
    return answer;
}
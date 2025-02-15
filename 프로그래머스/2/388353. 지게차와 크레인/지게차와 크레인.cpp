#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int board[52][52];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void prt() {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cout << (char)(board[i][j] + 'A') << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void bfs() {
    bool visited[52][52] = { false };
    
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = true;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx > n + 1 || ny < 0 || ny > m + 1) continue;
            
            if(visited[nx][ny] || board[nx][ny] >= 0) continue;
            
            visited[nx][ny] = true;
            q.push({nx,ny});
            board[nx][ny] = -2;
        }
    }
}

void all_remove(int k) {
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(board[i][j] == k) {
                
                // 임시 제거
                board[i][j] = -1;
            }
        }
    }
    
    
}

void side_remove(int k) {
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            
            // 해당 알파벳
            if(board[i][j] == k) {
                
                // 4방향 중 한 곳은 외부와 접촉
                if(board[i-1][j] == -2 || board[i+1][j] == -2 ||
                  board[i][j-1] == -2 || board[i][j+1] == -2) {
                    
                    // 제거
                    board[i][j] = -1;
                }
            }
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    n = storage.size();
    m = storage[0].size();
    
    for(int i = 0; i <= n + 1; ++i) {
        board[i][0] = board[i][m + 1] = -2;
    }
    for(int i = 0; i <= m + 1; ++i) {
        board[0][i] = board[n + 1][i] = -2;            
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            board[i + 1][j + 1] = storage[i][j] - 'A';
        }
    }
    
    for(int i = 0; i < requests.size(); ++i) {
        
        if(requests[i].size() == 1) {
            side_remove(requests[i][0] - 'A');
        }
        else{
            all_remove(requests[i][0] - 'A');
        }
        
        bfs();
    }
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(board[i][j] >= 0) answer++;
        }
    }
    
    return answer;
}
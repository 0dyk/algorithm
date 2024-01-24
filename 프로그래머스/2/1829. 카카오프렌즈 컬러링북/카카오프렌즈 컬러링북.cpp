#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int value = 0;
    int maxCnt = 0;
    
    int N = picture.size();
    int M = picture[0].size();
    
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(picture[i][j] == -1 || picture[i][j] == 0) continue;
            
            int cnt = 1;
            int now = picture[i][j];
            picture[i][j] = -1;
            
            queue<pair<int,int>> q;
            q.push({i, j});
            
            while(!q.empty()){
                pair<int,int> cur = q.front();
                q.pop();
                
                for(int k = 0; k < 4; ++k){
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    
                    if(nx < 0 || nx >= N || ny < 0 || ny >= M || 
                       picture[nx][ny] != now) continue;
                
                    picture[nx][ny] = -1;
                    cnt++;
                    q.push({nx,ny});
                }
            } // end::While
            
            if(cnt > maxCnt){
                maxCnt = cnt;
            }
            
            value++;
        }
    }
    
    vector<int> answer;
    answer.push_back(value);
    answer.push_back(maxCnt);
    
    return answer;
}
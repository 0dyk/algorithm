#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int k = 0; k < places.size(); ++k){
        int R = places[k].size();
        int C = places[k][0].size();        
        
        bool checked = false;
        
        // 함수 뺴서 리턴하면되지만.. 귀찮
        for(int i = 0; i < R; ++i){   
            for(int j = 0; j < C; ++j){
                if(places[k][i][j] != 'P') continue;
                
                for(int d1 = 0; d1 < 4; ++d1){
                    if(checked) break;
                    
                    for(int d2 = 0; d2 < 4; ++d2) {
                        if(checked) break;
                        
                        if(d1 != d2 && (d1 + d2) % 2 == 0) continue;
                        
                        int nx1 = i + dx[d1];
                        int ny1 = j + dy[d1];
                        
                        if(nx1 < 0 || nx1 >= R || ny1 < 0 || ny1 >= C) continue;
                        if(places[k][nx1][ny1] == 'X') continue;
                        
                        if(places[k][nx1][ny1] == 'P'){
                            checked = true;
                            break;
                        }
                        
                        int nx2 = nx1 + dx[d2];
                        int ny2 = ny1 + dy[d2];
                        
                        if(nx2 < 0 || nx2 >= R || ny2 < 0 || ny2 >= C) continue;
                        
                        if(places[k][nx2][ny2] == 'P'){
                            checked = true;
                            break;
                        }
                    }
                } // 주변 탐색 끝
            }
        } // 대기실 끝
        
        if(checked) answer.push_back(0);
        else answer.push_back(1);
    }
    
    return answer;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 연결 
bool connect[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = n;
    
    for(int i = 0; i < results.size(); ++i){
        connect[results[i][0]][results[i][1]] = true;
    }
    
    // 출발점 : i
    for(int k = 1; k <= n; ++k){
        // 도착점 : j
        for(int i = 1; i <= n; ++i){
            // 경유지 k
            for(int j = 1; j <= n; ++j){
                // i -> k 가능 && k -> j 가능
                if(connect[i][k] && connect[k][j]) {
                    connect[i][j] = true;
                }
            }
        }
    }
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i != j && !connect[i][j] && !connect[j][i]) {
                answer--;
                break;
            }
        }
    }
    
    return answer;
}
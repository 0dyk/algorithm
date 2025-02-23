#include <iostream>
#include <string>
#include <vector>

#define MAX_N 1000

using namespace std;

// __, __ = a의 최솟값
// 물건, B
int dp[41][121];

int solution(vector<vector<int>> info, int n, int m) {
    int answer = MAX_N;
    
    for(int i = 0; i < 41; ++i) {
        for(int j = 0; j < 121; ++j) {
            dp[i][j] = MAX_N;
        }
    }
    
    dp[0][0] = 0;
    
    for(int i = 1; i <= info.size(); ++i){
        
        for(int j = 0; j < m; ++j) {
            
            // a
            if(dp[i-1][j] + info[i-1][0] < dp[i][j]) {
                dp[i][j] = dp[i-1][j] + info[i-1][0];
            }

            // b
            if(j + info[i-1][1] < m) {
                if(dp[i-1][j] < dp[i][j + info[i-1][1]])
                dp[i][j + info[i-1][1]] = dp[i-1][j];
            }
        }
    }
    
    for(int j = 0; j < m; ++j) {
        if(dp[info.size()][j] < answer) answer = dp[info.size()][j];
    }
    
    if(answer >= n) answer = -1;
    
    
    return answer;
}
#include <string>
#include <vector>
#include <iostream>

#define MAX_SCORE 200

using namespace std;

int dp[151][151];

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    
    int max_alp = alp, max_cop = cop;
    
    for(int i = 0; i < problems.size(); ++i){
        if(max_alp < problems[i][0]) max_alp = problems[i][0];
        if(max_cop < problems[i][1]) max_cop = problems[i][1];
    }
    
    for(int i = alp; i <= max_alp; ++i) {
        for(int j = cop; j <= max_cop; ++j) {
            dp[i][j] = MAX_SCORE;
        }
    }

    dp[alp][cop] = 0;
    
    for(int i = alp; i <= max_alp; ++i) {
        for(int j = cop; j <= max_cop; ++j) {

            dp[i][j+1] = dp[i][j] + 1 > dp[i][j+1] ? dp[i][j+1] : dp[i][j] + 1;
            dp[i+1][j] = dp[i][j] + 1 > dp[i+1][j] ? dp[i+1][j] : dp[i][j] + 1;
            

            for(int k = 0; k < problems.size(); ++k){
                if(i >= problems[k][0] && j >= problems[k][1]){

                    int next_alp = max_alp < i + problems[k][2] ? max_alp : i + problems[k][2];
                    int next_cop = max_cop < j + problems[k][3] ? max_cop : j + problems[k][3];
                    
                    if(dp[i][j] + problems[k][4] < dp[next_alp][next_cop]) {
                        dp[next_alp][next_cop] = dp[i][j] + problems[k][4];
                    }
                }
            }
        }
    }
    
    answer = dp[max_alp][max_cop];
    
    return answer;
}
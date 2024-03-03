#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
int answer;

int dp[200002][2];
// 0 : 삼각형
// 1 : 마름모

int solution(int n, vector<int> tops) {
    answer = 0;
    N = 2 * n + 1;
    
    dp[1][0] = 1;
    
    for(int i = 2; i <= N; ++i){
        // 삼각형으로 끝내려면 이전 경우의 수 그대로
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        
        // 마름모로 끝내려면
        
        // 이전 끝난게 삼각형
        dp[i][1] = dp[i - 1][0];
            
        // i가 짝수고 머리위에 top
        if(i % 2 == 0 && tops[i / 2 - 1] == 1){
            dp[i][1] += dp[i - 1][0] + dp[i - 1][1];
        }
        
        // cout << i << " : "<< dp[i][0] << " " << dp[i][1] << '\n';
        dp[i][0] = dp[i][0] % 10007;
        dp[i][1] = dp[i][1] % 10007;
    }
    
    answer = (dp[N][0] + dp[N][1]) % 10007;
    
    return answer;
}
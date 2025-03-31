class Solution {
    public int solution(int alp, int cop, int[][] problems) {
        int answer = 0;
        
        int maxAlp = alp, maxCop = cop;
        for(int i = 0; i < problems.length; ++i) {
            if(problems[i][0] > maxAlp) maxAlp = problems[i][0];
            if(problems[i][1] > maxCop) maxCop = problems[i][1];
        }
        
        int[][] dp = new int[152][152];
        for(int i = alp; i <= maxAlp; ++i) {
            for(int j = cop; j <= maxCop; ++j) {
                dp[i][j] = 301;
            }
        }

        dp[alp][cop] = 0;
        
        for(int i = alp; i <= maxAlp; ++i) {
            for(int j = cop; j <= maxCop; ++j) {
                if(dp[i][j] + 1 < dp[i+1][j]) dp[i+1][j] = dp[i][j] + 1;
                if(dp[i][j] + 1 < dp[i][j+1]) dp[i][j+1] = dp[i][j] + 1;
                
                for(int k = 0; k < problems.length; ++k) {
                    if(i < problems[k][0] || j < problems[k][1]) continue;
                    
                    int na = Math.min(maxAlp, i + problems[k][2]);
                    int nc = Math.min(maxCop, j + problems[k][3]);
                    
                    if(dp[i][j] + problems[k][4] < dp[na][nc]) dp[na][nc] = dp[i][j] + problems[k][4];
                }
            }
        }
        
        answer = dp[maxAlp][maxCop];
        
        return answer;
    }
}
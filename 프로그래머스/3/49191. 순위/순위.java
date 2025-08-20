class Solution {
    
    boolean[][] winlose;
    
    public int solution(int n, int[][] results) {
        int answer = 0;
    
        winlose = new boolean[n+1][n+1];
        
        for(int i = 0; i < results.length; i++) {
                winlose[results[i][0]][results[i][1]] = true;
        }
        
        // i -> k -> j
        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    if(winlose[i][k] && winlose[k][j]) {
                        winlose[i][j] = true;
                    }
                }
            }
        }
        
        // answer
        for(int i = 1; i <= n; i++) {
            boolean flag = true;
            for(int j = 1; j <= n; j++) {
                if(i != j && !winlose[i][j] && !winlose[j][i]) {
                    flag = false;
                    break;
                }
            }
            
            if(flag) answer++;
        }
        
        return answer;
    }
}
class Solution {
    public int solution(int n, int[][] results) {
        int answer = n;

        boolean winLose[][] = new boolean[101][101];
        
        for(int i = 0; i < results.length; ++i) {
            winLose[results[i][0]][results[i][1]] = true;
            // System.out.println(results[i][0] + " / " + results[i][1]);
        }
    
        for(int k = 1; k <= n; ++k) {
            for(int i = 1; i<= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    if(winLose[i][k] && winLose[k][j]) {
                        winLose[i][j] = true;
                    }
                }
            }
        }
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                // i, j의 경기 결과를 알 수 없을 때
                if (i != j && !winLose[i][j] && !winLose[j][i]) {
                    answer--;
                    break;
                }
            }
        }
        
        return answer;
    }
}
class Solution {
    boolean[] visited;
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        visited = new boolean[n];
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(n, computers, i);   
                answer++;
            }
        }
        
        return answer;
    }
    
    void dfs(int n, int[][] computers, int x) {
        visited[x] = true;
        
        for(int i = 0; i < n; i++) {
            if(i == x || visited[i]) continue;
            
            if(computers[i][x] == 1) {
                dfs(n, computers, i);
            }
        }
    }
}
import java.util.*;

class Solution {
    
    int[][] dxdy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    public int solution(int[][] maps) {
        int answer = -1;
        
        int n = maps.length;
        int m = maps[0].length;
        
        int[][] dist = new int[n][m];
        
        Queue<int[]> q = new ArrayDeque<>();
        
        q.offer(new int[] {0, 0});
        dist[0][0] = 1;
        
        while(!q.isEmpty()) {
            int[] cur = q.poll();

            if(cur[0] == n - 1 && cur[1] == m - 1) {
                answer = dist[cur[0]][cur[1]];
                break;
            }
            
            for(int i = 0; i < 4; i++) {
                int nx = cur[0] + dxdy[i][0];
                int ny = cur[1] + dxdy[i][1];
                
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                
                if(maps[nx][ny] == 0) {
                    continue;
                }
                
                if(dist[nx][ny] != 0) {
                    continue;
                }
                
                dist[nx][ny] = dist[cur[0]][cur[1]] + 1;
                q.offer(new int[] {nx ,ny});
            }
        }
        
        return answer;
    }
}
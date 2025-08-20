import java.util.*;

class Solution {
    
    int[] dist;
    List<Integer>[] adjList;
    
    public int solution(int n, int[][] edge) {
        int answer = 0;
        
        // init
        dist = new int[n + 1];
        Arrays.fill(dist, -1);
        adjList = new ArrayList[n + 1];
        for(int i = 0; i < n + 1; i++) {
            adjList[i] = new ArrayList<>();
        }
        
        // edge -> adgList
        for(int i = 0; i < edge.length; i++) {
            adjList[edge[i][0]].add(edge[i][1]);
            adjList[edge[i][1]].add(edge[i][0]);
        }        
        
        // bfs
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(1);
        dist[1] = 0;
        
        while(!q.isEmpty()) {
            int cur = q.poll();
            
            for(int i = 0; i < adjList[cur].size(); i++) {
                int next = adjList[cur].get(i);
                
                if(dist[next] != -1) continue;
                
                dist[next] = dist[cur] + 1;
                q.offer(next);
            }
        }
        
        // max dist
        int max_dist = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] > max_dist) max_dist = dist[i];
        }
        
        // count
        for(int i = 1; i <= n; i++) {
            if(dist[i] == max_dist) answer++;
        }
        
        return answer;
    }
}
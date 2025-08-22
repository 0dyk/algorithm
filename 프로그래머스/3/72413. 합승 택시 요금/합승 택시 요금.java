import java.util.*;

class Solution {
    
    int[] aToPointDist;
    int[] bToPointDist;
    int[] sToPointDist;
    
    List<int[]>[] adjList;
    
    public int solution(int n, int s, int a, int b, int[][] fares) {
        int answer = Integer.MAX_VALUE;
        
        // a, b, c에서 다른 지점까지의 최단거리
        
        // fares to adjList
        adjList = new ArrayList[n + 1];
        for(int i = 0; i < n + 1; i++) {
            adjList[i] = new ArrayList<>();
        }
        
        for(int i = 0; i < fares.length; i++) {
            adjList[fares[i][0]].add(new int[] {fares[i][1], fares[i][2]});
            adjList[fares[i][1]].add(new int[] {fares[i][0], fares[i][2]});
        }
        
        // init
        aToPointDist = new int[n + 1];
        bToPointDist = new int[n + 1];
        sToPointDist = new int[n + 1];
        
        Arrays.fill(aToPointDist, Integer.MAX_VALUE);
        Arrays.fill(bToPointDist, Integer.MAX_VALUE);
        Arrays.fill(sToPointDist, Integer.MAX_VALUE);
        aToPointDist[a] = 0;
        bToPointDist[b] = 0;
        sToPointDist[s] = 0;
        
        // 다익스트라 * 3
        dijkstra(a, aToPointDist);
        dijkstra(b, bToPointDist);
        dijkstra(s, sToPointDist);
        
        // 최소값
        for(int i = 1; i <= n; i++) {
            int sum = aToPointDist[i] + bToPointDist[i] + sToPointDist[i];
            if(sum < answer) {
                answer = sum;
            }
        }
        
        return answer;
    }
    
    void dijkstra(int start, int[] dist) {
        
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a, b) -> a[0] - b[0]
        );
        pq.offer(new int[] {0, start});
        
        while(!pq.isEmpty()) {
            int cost = pq.peek()[0];
            int cur = pq.peek()[1];
            pq.poll();
            
            for(int i = 0; i < adjList[cur].size(); i++) {
                int nx = adjList[cur].get(i)[0];
                int nc = adjList[cur].get(i)[1];
                
                if(dist[nx] > cost + nc) {
                    dist[nx] = cost + nc;
                    pq.offer(new int[] { cost + nc, nx });
                }
            }
        }
    }
}
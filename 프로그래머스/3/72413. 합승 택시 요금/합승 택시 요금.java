import java.util.*;

class Solution {

    static final int INF = 2100000000;
    
    static int N;
    
    static int[] sToPoint;
    static int[] aToPoint;
    static int[] bToPoint;
    
    static List<int[]>[] adjList;
    
    public static int solution(int n, int s, int a, int b, int[][] fares) {
        int answer = INF;
        
        N = n;
        
        sToPoint = new int[n + 1];
        aToPoint = new int[n + 1];
        bToPoint = new int[n + 1];
        
        adjList = new ArrayList[n + 1];
        for(int i = 1; i < n + 1; ++i){
            adjList[i] = new ArrayList<>();
        }
        
        for(int i = 0; i < fares.length; ++i){
            adjList[fares[i][0]].add(new int[] {fares[i][1], fares[i][2]});
            adjList[fares[i][1]].add(new int[] {fares[i][0], fares[i][2]});
        }
        
        // X -> S
        dijkstra(s, sToPoint);
        // B -> X
        dijkstra(b, bToPoint);
        // A -> X
        dijkstra(a, aToPoint);
        
        for(int i = 1; i <= n; ++i) {
        	// if(i == s || i == a || i == b) continue;
        	
        	int tmp = sToPoint[i] + aToPoint[i] + bToPoint[i];
        	
        	if(tmp < answer) answer = tmp;
        }

        
        return answer;
    }

    public static void dijkstra (int start, int[] dist){
        Queue<int[]> pq = new PriorityQueue<>((a,b) -> a[0] - b[0]);
        
        for(int i = 0; i <= N; ++i){
            dist[i] = INF;
        }
        
        pq.offer(new int[] {0, start});
        dist[start] = 0;
        
        while(!pq.isEmpty()){
        	int now = pq.poll()[1];
        	
        	for(int i = 0; i < adjList[now].size(); ++i) {
        		int nx = adjList[now].get(i)[0];
        		int nc = adjList[now].get(i)[1] + dist[now];
        		
        		if(dist[nx] > nc) {
        			dist[nx] = nc;
        			pq.offer(new int[] {nc, nx});
        		}
        	}
        }
    }
}









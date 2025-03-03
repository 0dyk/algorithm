import java.util.*;

class Solution {
    static int[] inDegree = new int[1000001];
    static int[] outDegree = new int[1000001];
    static boolean[] visited = new boolean[1000001];
    static boolean[] exists = new boolean[1000001];
    static List[] adjList = new ArrayList[1000001];

    public int[] solution(int[][] edges) {
        int[] answer = new int[4];
        // 도넛 -> 순회 -> 1 out 1 in
        // 막대 -> 1자 -> 1 out / 1 in / 1 out 1 in
        // 8자 -> 1 out 1 in / 2 out 2 in
        
        // 들어오는 점이 없다 + 나가는 점이 1개 초과 -> 추가된 정점?
        
        for(int i = 0; i < 1000001; ++i){
            adjList[i] = new ArrayList<Integer>();
        }
        
        for(int i = 0; i < edges.length; ++i){
            outDegree[edges[i][0]]++;
            inDegree[edges[i][1]]++;
            
            exists[edges[i][0]] = exists[edges[i][1]] = true;
            
            adjList[edges[i][0]].add(edges[i][1]);
            adjList[edges[i][1]].add(edges[i][0]);
        }
        
        for(int i = 1; i <= 1000000; ++i){
            if(inDegree[i] == 0 && outDegree[i] > 1) {
                answer[0] = i;
                break;
            }
        }
        
        for(int i = 1; i <= 1000000; ++i) {
            if(visited[i] || !exists[i] ||i == answer[0]) continue;
            visited[i] = true;
            
            int node_count = 0;
            int edge_count = 0;
            
            Queue<Integer> q = new ArrayDeque<>();
            q.offer(i);
            
            while(!q.isEmpty()) {
                int cur = q.poll();
                
                node_count++;
                edge_count += inDegree[cur] + outDegree[cur];
                
                for(int j = 0; j < adjList[cur].size(); ++j){
                    int nx = (int)adjList[cur].get(j);
                    if(visited[nx] || nx == answer[0]) continue;
                    visited[nx] = true;
                    q.offer(nx);
                }
            }
            
            if (node_count == (edge_count - 1) / 2) answer[1]++;
            else if (node_count - 1 == (edge_count - 1) / 2) answer[2]++;
            else answer[3]++;
        }
        
        // answer :  생성한 정점, 도넛, 막대, 8자
        
        return answer;
    }
}
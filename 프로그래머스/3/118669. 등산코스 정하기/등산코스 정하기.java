import java.util.*;

class Solution {

    static Set<Integer> entr;
    static Set<Integer> smt;
    static List<int[]>[] adj;
    static int[] visited;
    static int[] intens;
    
    public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
        int[] answer = {0, 0};
        
        entr = new HashSet<>();
        smt = new HashSet<>();
        adj = new ArrayList[n+1];
        visited = new int[n+1];
        intens = new int[n+1];
        
        for(int i = 0; i < n+1; ++i) adj[i] = new ArrayList<>();
        for(int i = 0; i < gates.length; ++i) entr.add(gates[i]);
        for(int i = 0; i < summits.length; ++i) smt.add(summits[i]);
        for(int i = 0; i < paths.length; ++i){
            adj[paths[i][0]].add(new int[] {paths[i][1], paths[i][2]});
            adj[paths[i][1]].add(new int[] {paths[i][0], paths[i][2]});
        }
        
        int minIntensity = 10000001;
        int start = 50001, end = 0;
        
        for(int i = 0; i < gates.length; ++i) {
            int gate = gates[i];
            
            PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
            pq.add(new int[] {0, gate});
            visited[gate] = gate;
            intens[gate] = 0;
            
            while(!pq.isEmpty()) {
                int inten = pq.peek()[0];
                int cur = pq.peek()[1];
                pq.poll();
                
                if(inten > minIntensity) continue;
                
                if(smt.contains(cur)) {
                    if(inten < minIntensity || (inten == minIntensity && cur < end)) {
                        minIntensity = inten;
                        start = gate;
                        end = cur;
                    }
                    continue;
                }
                
                for(int j = 0; j < adj[cur].size(); ++j) {
                    int nx = adj[cur].get(j)[0];
                    int ni = Math.max(inten, adj[cur].get(j)[1]);

                    if(entr.contains(nx)) continue;
                    if(visited[nx] == gate && intens[nx] <= ni) continue;

                    visited[nx] = gate;
                    intens[nx] = ni;

                    pq.add(new int[] {ni, nx});
                }
            }
        }
        
        answer[0] = end;
        answer[1] = minIntensity;
        
        return answer;
    }
}
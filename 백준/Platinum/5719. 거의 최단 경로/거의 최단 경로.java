import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N, M;
    static int S, D;

    // [0] = next, [1] = dist
    static ArrayList<int[]>[] adjList;
    static int[] dist;
    static ArrayList<Integer>[] beforePoint;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        adjList = new ArrayList[500];
        beforePoint = new ArrayList[500];
        dist = new int[500];
        visited = new boolean[500];

        for(int i = 0; i < 500; i++) {
            adjList[i] = new ArrayList<>();
            beforePoint[i] = new ArrayList<>();
        }

        // 거의 최단 경로 -> 최단 경로에 포함되지 않는 도로로만 이루어진 경로 중 가장 짧은 것

        while(true) {
            String[] str = br.readLine().split(" ");
            N = Integer.parseInt(str[0]);
            M = Integer.parseInt(str[1]);

            if(N == 0 && M == 0) break;

            for(int i = 0; i < N; i++) {
                adjList[i].clear();
                beforePoint[i].clear();
                dist[i] = 1000 * 501;
            }

            str = br.readLine().split(" ");
            S = Integer.parseInt(str[0]);
            D = Integer.parseInt(str[1]);

            for(int i = 0; i < M; i++) {
                str = br.readLine().split(" ");

                int U = Integer.parseInt(str[0]);
                int V = Integer.parseInt(str[1]);
                int P = Integer.parseInt(str[2]);

                adjList[U].add(new int[]{V, P});
            }

            // dijkstra

            // { 현재 길이, 현재 위치 }
            PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> o1[0] - o2[0]);
            pq.offer(new int[]{0, S});
            dist[S] = 0;

            while(!pq.isEmpty()) {
                int curDist = pq.peek()[0];
                int curPoint = pq.poll()[1];

                for(int i = 0; i < adjList[curPoint].size(); i++) {
                    int nextPoint = adjList[curPoint].get(i)[0];
                    int nextDist = curDist + adjList[curPoint].get(i)[1];

                    // 최단 길이 갱신
                    if(nextDist < dist[nextPoint]) {
                        dist[nextPoint] = nextDist;
                        beforePoint[nextPoint].clear();
                        beforePoint[nextPoint].add(curPoint);

                        pq.offer(new int[]{ nextDist, nextPoint });
                    }
                    else if(nextDist == dist[nextPoint] && !beforePoint[nextPoint].contains(curPoint)) {
                        beforePoint[nextPoint].add(curPoint);
                        pq.offer(new int[]{ nextDist, nextPoint });
                    }
                }
            }

            // 역추적?
            Queue<Integer> q = new ArrayDeque<>();
            q.offer(D);

            Arrays.fill(visited, false);
            visited[D] = true;

            while(!q.isEmpty()) {
                int cur = q.poll();

                for(int i = 0; i < beforePoint[cur].size(); i++) {
                    int before = beforePoint[cur].get(i);

                    for (int j = 0; j < adjList[before].size(); j++) {
                        if (adjList[before].get(j)[0] == cur) {
                            adjList[before].get(j)[0] = -1;
                            break;
                        }
                    }

                    if(!visited[before]) {
                        visited[before] = true;
                        q.offer(before);
                    }
                }
            }

            // one more dijkstra
            for(int i = 0; i < N; i++) {
                dist[i] = 1000 * 501;
            }

            pq.offer(new int[]{0, S});
            dist[S] = 0;

            int ret = -1;

            while(!pq.isEmpty()) {
                int curDist = pq.peek()[0];
                int curPoint = pq.poll()[1];

                if(curPoint == D) {
                    ret = curDist;
                    break;
                }

                for(int i = 0; i < adjList[curPoint].size(); i++) {
                    int nextPoint = adjList[curPoint].get(i)[0];

                    if(nextPoint == -1) continue;

                    int nextDist = curDist + adjList[curPoint].get(i)[1];

                    if(nextDist < dist[nextPoint]) {
                        dist[nextPoint] = nextDist;
                        pq.offer(new int[]{ nextDist, nextPoint });
                    }
                }
            }

            sb.append(ret).append('\n');
        }

        System.out.print(sb.toString());
    }
}

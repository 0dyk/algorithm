import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

    static int N, M;
    static int LOG;
    static List<Integer>[] adjList;
    static int[][] parent;
    static int[] depth;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(br.readLine());
        adjList = new ArrayList[N + 1];
        depth = new int[N + 1];

        LOG = 0;
        while ((1 << LOG) <= N) LOG++;

        parent = new int[N + 1][LOG + 1];

        for(int i = 0; i < N + 1; i++) {
            adjList[i] = new ArrayList<>();
        }

        for(int i = 0; i < N - 1; i++) {
            String[] str = br.readLine().split(" ");

            int a = Integer.parseInt(str[0]);
            int b = Integer.parseInt(str[1]);

            adjList[a].add(b);
            adjList[b].add(a);
        }

        makeTree(0, 1);

        for(int dep = 1; dep < LOG; dep++) {
            for(int node = 1; node < N + 1; node++) {
                parent[node][dep] = parent[parent[node][dep - 1]][dep - 1];
            }
        }

        M = Integer.parseInt(br.readLine());
        for(int i = 0; i < M; i++) {
            String[] str = br.readLine().split(" ");

            int a = Integer.parseInt(str[0]);
            int b = Integer.parseInt(str[1]);

            sb.append(LCA(a, b)).append("\n");
        }

        System.out.print(sb.toString());
    }

    static int LCA(int a, int b) {
        if(depth[a] > depth[b]) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        for(int i = LOG; i >= 0; i--) {
            if(depth[b] - depth[a] >= (1 << i)) {
                b = parent[b][i];
            }
        }

        if(a == b) return a;

        for(int i = LOG; i >= 0; i--) {
            if(parent[a][i] != parent[b][i]) {
                a = parent[a][i];
                b = parent[b][i];
            }
        }

        return parent[a][0];
    }

    static void makeTree(int par, int node) {
        parent[node][0] = par;
        depth[node] = depth[par] + 1;

        for(int i = 0; i < adjList[node].size(); i++) {
            if(adjList[node].get(i) == par) continue;

            makeTree(node, adjList[node].get(i));
        }
    }
}
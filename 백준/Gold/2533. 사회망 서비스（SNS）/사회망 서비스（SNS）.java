import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

    static int N;
    static List<Integer>[] adj;
    // dp[i][0] : i 노드가 얼리 아닐 때, dp[i][0] : i 노드가 얼리일 때,
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        dp = new int[N + 1][2];

        adj = new ArrayList[N + 1];
        for(int i = 1; i <= N; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int i = 0; i < N - 1; i++) {
            String[] str = br.readLine().split(" ");
            int a = Integer.parseInt(str[0]);
            int b = Integer.parseInt(str[1]);

            adj[a].add(b);
            adj[b].add(a);
        }

        DFS(0, 1);

        int answer = Math.min(dp[1][0], dp[1][1]);

        System.out.println(answer);
    }

    static void DFS(int parent, int child) {
        dp[child][0] = 0;
        dp[child][1] = 1;

        for (int node : adj[child]) {
            if (node == parent) continue;

            DFS(child, node);
            dp[child][0] += dp[node][1];
            dp[child][1] += Math.min(dp[node][0], dp[node][1]);
        }
    }
}
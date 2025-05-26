import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N, M, K;
    static int[][] parent;
    static int[] candy;
    static List<Integer> group;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] str = br.readLine().split(" ");

        N = Integer.parseInt(str[0]);
        M = Integer.parseInt(str[1]);
        K = Integer.parseInt(str[2]);

        parent = new int[N + 1][2];
        for(int i = 1; i <= N; ++i) {
            parent[i][0] = i;
            parent[i][1] = 1;
        }

        candy = new int[N + 1];
        str = br.readLine().split(" ");
        for(int i = 0; i < str.length; ++i) {
            candy[i + 1] = Integer.parseInt(str[i]);
        }

        for(int i = 0; i < M; ++i) {
            str = br.readLine().split(" ");

            int a = Integer.parseInt(str[0]);
            int b = Integer.parseInt(str[1]);

            union(a, b);
        }

        group = new ArrayList<>();

        for(int i = 1; i <= N; ++i) {
            if(parent[i][0] == i) group.add(i);
            else {
                candy[find(i)] += candy[i];
                parent[find(i)][1] += 1;
            }
        }

        dp = new int[group.size() + 1][K + 1];

        for(int i = 0; i < group.size(); ++i) {
            // 그룹장, 그룹수, 캔디수
            int idx = group.get(i);
            int group_size = parent[idx][1];
            int candy_count = candy[idx];

            for(int j = 0; j < K; ++j) {
                if(j >= group_size) {
                    dp[i+1][j] = Math.max(dp[i][j], dp[i][j - group_size] + candy_count);
                }
                else {
                    dp[i+1][j] = dp[i][j];
                }
            }
        }

        System.out.println(dp[group.size()][K - 1]);
    }


    static int find (int x) {
        if(parent[x][0] == x) return x;
        return parent[x][0] = find(parent[x][0]);
    }

    static void union(int a, int b) {
        int fa = find(a);
        int fb = find(b);

        if(fa < fb) {
            parent[fb][0] = fa;
        }
        else {
            parent[fa][0] = fb;
        }
    }
}
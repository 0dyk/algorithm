import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    // N <= 100,000
    static int N;
    // [i][0] -> [i][1] : a -> b / a, b <= 500,000
    static int[][] adj;
    static int[][] dp;
    static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        intAndInput();
        solve();
    }

    static void intAndInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        N = Integer.parseInt(br.readLine());
        adj = new int[N][2];
        dp = new int[N][2];

        for (int i = 0; i < N; i++) {
            String[] line = br.readLine().split(" ");
            adj[i][0] = Integer.parseInt(line[0]);
            adj[i][1] = Integer.parseInt(line[1]);
        }
    }

    static void solve() {
        Arrays.sort(adj, (o1, o2) -> o1[0] - o2[0]);

        int size = 0;
        dp[0][1] = adj[0][1];

        for(int i = 1; i < N; i++) {
            int idx = binarySearch(0, size + 1, adj[i][1]);

            dp[idx][1] = adj[i][1];

            if(idx == size + 1) {
                size++;
            }

            dp[i][0] = idx;
        }

        sb.append(N - size - 1).append("\n");

        Stack<Integer> st = new Stack<>();
        for(int i = N - 1; i >= 0; i--) {
            if(dp[i][0] != size) {
                st.push(adj[i][0]);
            }
            else {
                size--;
            }
        }

        while (!st.isEmpty()) {
            sb.append(st.pop()).append("\n");
        }

        System.out.println(sb.toString());
    }



    private static int binarySearch(int left, int right, int k) {
        while(left < right) {
            int mid = (left + right) / 2;

            if(dp[mid][1] < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return right;
    }
}
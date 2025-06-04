import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    static int N, M, K;

    static int[] parent;
    static int[] nodes;
    static int[] answer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        K = Integer.parseInt(input[2]);

        nodes = new int[M];
        parent = new int[M + 1];
        answer = new int[K];

        input = br.readLine().split(" ");
        for (int i = 0; i < M; i++) {
            int k = Integer.parseInt(input[i]);
            nodes[i] = k;
            parent[i] = i;
        }
        parent[M] = M;

        Arrays.sort(nodes);

        input = br.readLine().split(" ");
        for(int i = 0; i < K; i++) {
            int cur = Integer.parseInt(input[i]);

            int idx = find(upperBound(cur));

            union(idx, idx + 1);

            sb.append(nodes[idx]).append("\n");
        }

        System.out.print(sb.toString());
    }

    static int upperBound(int x) {
        int left = 0;
        int right = M;

        while(left < right) {
            int mid = (left + right) / 2;

            if(nodes[mid] > x) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }

    static int find(int x) {
        if(parent[x] == x) return x;
        else return parent[x] = find(parent[x]);
    }

    static void union(int a, int b) {
        int fa = find(a);
        int fb = find(b);

        parent[fa] = fb;
    }
}

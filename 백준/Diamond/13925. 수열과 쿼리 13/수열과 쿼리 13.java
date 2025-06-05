import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

    // 10^9 + 7
    static int MOD = 1_000_000_007;

    static int N, M;
    static long[] arr;
    static long[] segmentTree;
     static long[][] lazyTree;
    static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        N = Integer.parseInt(br.readLine());
        arr = new long[N + 1];
        segmentTree = new long[N * 4];
        lazyTree = new long[N * 4][2];

        String[] str = br.readLine().split(" ");
        for(int i = 0; i < N; i++) {
            arr[i + 1] = Integer.parseInt(str[i]);
        }

        for (int i = 0; i < N * 4; i++) {
            lazyTree[i][0] = 1;
        }

        makeTree(1, N, 1);

        M = Integer.parseInt(br.readLine());
        for(int i = 0; i < M; i++) {
            str = br.readLine().split(" ");

            int k = Integer.parseInt(str[0]);
            int x = Integer.parseInt(str[1]);
            int y = Integer.parseInt(str[2]);
            int v = k != 4 ? Integer.parseInt(str[3]) : 0;

            // PLUS
            if(k == 1) {
                AToBPlusXMultipleY(1, N, 1, x, y, v, 1);
            }
            // Multiple
            else if(k == 2) {
                AToBPlusXMultipleY(1, N, 1, x, y, 0, v);
            }
            // replace
            else if(k == 3) {
                AToBPlusXMultipleY(1, N, 1, x, y, v, 0);
            }
            // getSum
            else if(k == 4) {
                long sum = AToBSum(1, N, 1, x, y);
                sb.append(sum).append("\n");
            }
        }

        System.out.print(sb.toString());
    }

    // Segment Tree 생성
    static long makeTree(int left, int right, int node) {
        if(left == right) return segmentTree[node] = arr[left];
        else return (segmentTree[node] = makeTree(left, (left + right) / 2, node * 2)
                +  makeTree((left + right) / 2 + 1, right, node * 2 + 1)) % MOD;
    }

    // A to B 의 합 % MOD 리턴
    private static long AToBSum(int left, int right, int node, int a, int b) {
        lazyUpdate(left, right, node);
        if(a > right || b < left) return 0;

        if(a <= left && b >= right) {
            return segmentTree[node];
        }

        int mid = (left + right) / 2;

        return (AToBSum(left, mid, node * 2, a, b)
                + AToBSum(mid + 1, right, node * 2 + 1, a, b)) % MOD;
    }

    // A to B 구간에 + x, * y
    private static void AToBPlusXMultipleY(int left, int right, int node, int a, int b, int x, int y) {
        lazyUpdate(left, right, node);
        if(a > right || b < left) return;

        if(a <= left && b >= right) {
            lazyTree[node][0] = y;
            lazyTree[node][1] = x;
            lazyUpdate(left, right, node);

            return;
        }

        int mid = (left + right) / 2;

        AToBPlusXMultipleY(left, mid, node * 2, a, b, x, y);
        AToBPlusXMultipleY(mid + 1, right, node * 2 + 1, a, b, x, y);

        segmentTree[node] = (segmentTree[node * 2] + segmentTree[node * 2 + 1]) % MOD;
    }

    // Lazy Propagation
    private static void lazyUpdate(int left, int right, int node) {
        if(lazyTree[node][0] == 1 && lazyTree[node][1] == 0) {
            return;
        }

        segmentTree[node] = (segmentTree[node] * lazyTree[node][0] % MOD
                + (lazyTree[node][1] * (right - left + 1)) % MOD) % MOD;

        if(left != right) {
            for(int i = node * 2; i <= node * 2 + 1; i++) {
                lazyTree[i][0] = lazyTree[i][0] * lazyTree[node][0] % MOD;
                lazyTree[i][1] = (lazyTree[i][1] * lazyTree[node][0] % MOD
                                + lazyTree[node][1]) % MOD;
            }
        }

        lazyTree[node][0] = 1;
        lazyTree[node][1] = 0;
    }
}
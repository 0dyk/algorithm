import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int MAX_SIZE = 1000000 * 4;
    static int N;

    static int[] tree = new int[MAX_SIZE * 4];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(br.readLine());

        for(int i = 0; i < N; i++) {
            String[] str = br.readLine().split(" ");

            int A, B, C;
            A = Integer.parseInt(str[0]);

            if(A == 1) {
                B = Integer.parseInt(str[1]);

                int num = findNodeOne(1, MAX_SIZE, 1, B);
                sb.append(num).append("\n");
            }
            else if(A == 2) {
                B = Integer.parseInt(str[1]);
                C = Integer.parseInt(str[2]);

                updateNode(1, MAX_SIZE, 1, B, C);
            }
            else {
                sb.append("error").append("\n");
                continue;
            }
        }

        System.out.print(sb.toString());
    }

    // idx 사탕을 diff 만큼 +-
    private static void updateNode(int left, int right, int node, int idx, int diff) {
        if(idx < left || idx > right) return;

        if(left == right) {
            tree[node] += diff;
            return;
        }

        int mid = (left + right) / 2;
        updateNode(left, mid, node * 2, idx, diff);
        updateNode(mid + 1, right, node * 2 + 1, idx, diff);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    // idx 번째 찾기
    private static int findNodeOne(int left, int right, int node, int idx) {
        if(left == right) {
            updateNode(1, MAX_SIZE, 1, left, -1);
            return left;
        }

        int mid = (left + right) / 2;
        int leftSize = tree[node * 2];

        // 좌측
        if(idx <= leftSize) {
            return findNodeOne(left, mid, node * 2, idx);
        }
        // 우측
        else {
            return findNodeOne(mid + 1, right, node * 2 + 1, idx - leftSize);
        }
    }
}

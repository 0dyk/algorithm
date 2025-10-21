import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {

    static int N;
    static HashMap<Integer, Integer> ALineNumToIdx;

    static int[] segTree;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(br.readLine());
        ALineNumToIdx = new HashMap<>();
        segTree = new int[N * 4];
        // make Tree

        String[] str = br.readLine().split(" ");
        for(int i = 0; i < N; i++) {
            ALineNumToIdx.put(Integer.parseInt(str[i]), i + 1);
        }

        long answer = 0;

        str = br.readLine().split(" ");
        for(int i = 0; i < N; i++) {
            // B 라인 번호
            int k = Integer.parseInt(str[i]);

            // A라인에서 일치하는 번호의 위치를 찾고 연결
            int AIdx = ALineNumToIdx.get(k);

            updateTree(1, N, 1, AIdx);

            // 그 오른쪽에 있는 것들의 개수를 구한다.
            // k + 1 ~ N까지
            answer += getSum(1, N, 1, AIdx + 1, N);
        }

        System.out.println(answer);
    }

    private static long getSum(int left, int right, int node, int a, int b) {
        if(a > right || b < left) return 0;
        if(a <= left && b >= right) return segTree[node];

        int mid = (left + right) / 2;
        return getSum(left, mid, node * 2, a, b) + getSum(mid + 1, right, node * 2 + 1, a, b);
    }

    private static void updateTree(int left, int right, int node, int idx) {
        if(idx < left || idx > right) return;
        if(left == right) {
            segTree[node] += 1;
            return;
        }

        int mid = (left + right) / 2;
        updateTree(left, mid, node * 2, idx);
        updateTree(mid + 1, right, node * 2 + 1, idx);

        segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
    }


}

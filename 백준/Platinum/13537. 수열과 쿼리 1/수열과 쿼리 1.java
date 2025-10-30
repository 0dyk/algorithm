import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.TreeSet;

public class Main {

    static int N, M;
    static int[] inputArray;
    static List<Integer>[] mergeSegmentTree;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        // 1 <= N <= 10만
        N = Integer.parseInt(br.readLine());
        inputArray = new int[N + 1];
        mergeSegmentTree = new ArrayList[N * 4];

        String[] str = br.readLine().split(" ");
        for(int i = 0; i < N; i++) {
            inputArray[i + 1] = Integer.parseInt(str[i]);
        }

        makeTree(1, N, 1);

        // 1 <= M <= 10만
        M = Integer.parseInt(br.readLine());
        for(int i = 0; i < M; i++) {
            str = br.readLine().split(" ");

            int a = Integer.parseInt(str[0]);
            int b = Integer.parseInt(str[1]);
            int k = Integer.parseInt(str[2]);

            int cnt =getCount(1, N, 1, a, b, k);
            sb.append(cnt).append('\n');
        }

        System.out.print(sb.toString());
    }

    private static int upperBound(int node, int k) {
        int left = 0, right = mergeSegmentTree[node].size();

        while(left < right) {
            int mid = (left + right) / 2;

            if(mergeSegmentTree[node].get(mid) <= k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }

    private static int getCount(int left, int right, int node, int a, int b, int k) {
        if(a > right || b < left) return 0;
        if(a <= left && b >= right) {
            int idx = upperBound(node, k);
            return mergeSegmentTree[node].size() - idx;
        }

        int mid = (left + right) / 2;
        return getCount(left, mid, node * 2, a, b, k) + getCount(mid + 1, right, node * 2 + 1, a, b, k);
    }

    private static void makeTree(int left, int right, int node) {
        mergeSegmentTree[node] = new ArrayList<>();

        if(left == right) {
            mergeSegmentTree[node].add(inputArray[left]);
            return;
        }

        int mid = (left + right) / 2;
        makeTree(left, mid, node * 2);
        makeTree(mid + 1, right, node * 2 + 1);

        // 머지 병합하기
        List<Integer> leftList = mergeSegmentTree[node * 2];
        List<Integer> rightList = mergeSegmentTree[node * 2 + 1];

        int i = 0, j = 0;
        while (i < leftList.size() && j < rightList.size()) {
            if (leftList.get(i) <= rightList.get(j))
                mergeSegmentTree[node].add(leftList.get(i++));
            else
                mergeSegmentTree[node].add(rightList.get(j++));
        }

        while (i < leftList.size()) mergeSegmentTree[node].add(leftList.get(i++));
        while (j < rightList.size()) mergeSegmentTree[node].add(rightList.get(j++));
    }
}

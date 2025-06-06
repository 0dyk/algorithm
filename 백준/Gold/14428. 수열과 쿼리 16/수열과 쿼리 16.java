import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {

    static int N, M;
    static int[] arr;
    static Node[] segmentTree;
    static StringBuilder sb;
    static Node MAX_NODE = new Node(-1, 1_000_000_001);

    static class Node {
        int idx;
        int value;

        public Node(int idx, int x) {
            this.idx = idx;
            this.value = x;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        N = Integer.parseInt(br.readLine());
        arr = new int[N + 1];
        segmentTree = new Node[N * 4];

        String[] str = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            arr[i + 1] = Integer.parseInt(str[i]);
        }

        makeTree(1, N, 1);

        M = Integer.parseInt(br.readLine());
        for(int i = 0; i < M; i++) {
            str = br.readLine().split(" ");
            int k = Integer.parseInt(str[0]);
            int a = Integer.parseInt(str[1]);
            int b = Integer.parseInt(str[2]);

            switch (k) {
                case 1:
                    update(1, N, 1, a, b);
                    break;
                case 2:
                    sb.append(getValue(1, N, 1, a, b).idx).append("\n");
                    break;
            }
        }

        System.out.println(sb.toString());
    }

    static void makeTree(int left, int right, int node) {
        if(left == right) {
            segmentTree[node] = new Node(left, arr[left]);
        }
        else {
            int mid = (left + right) / 2;
            makeTree(left, mid, node * 2);
            makeTree(mid + 1, right, node * 2 + 1);

            if(segmentTree[node * 2].value <= segmentTree[node * 2 + 1].value) {
                segmentTree[node] = new Node(segmentTree[node * 2].idx, segmentTree[node * 2].value);
            }
            else segmentTree[node] = new Node(segmentTree[node * 2 + 1].idx, segmentTree[node * 2 + 1].value);
        }
    }

    static void update(int left, int right, int node, int a, int v) {
        if(a < left || a > right) return;

        if(left == right) {
            segmentTree[node].value = v;
            return;
        }

        int mid = (left + right) / 2;

        update(left, mid, node * 2, a, v);
        update(mid + 1, right, node * 2 + 1, a, v);

        if(segmentTree[node * 2].value <= segmentTree[node * 2 + 1].value) {
            segmentTree[node].idx = segmentTree[node * 2].idx;
            segmentTree[node].value = segmentTree[node * 2].value;
        }
        else {
            segmentTree[node].idx = segmentTree[node * 2 + 1].idx;
            segmentTree[node].value = segmentTree[node * 2 + 1].value;
        }
    }

    static Node getValue(int left, int right, int node, int a, int b) {
        if(a > right || b < left) return MAX_NODE;

        if(a <= left && b >= right) return segmentTree[node];

        int mid = (left + right) / 2;

        Node lNode = getValue(left, mid, node * 2, a, b);
        Node rNode  = getValue(mid + 1, right, node * 2 + 1, a, b);

        if(lNode.value <= rNode.value) return lNode;
        else return rNode;
    }
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static class Node {
        long sum;
        Node left, right;

        public Node(long sum, Node left, Node right) {
            this.sum = sum;
            this.left = left;
            this.right = right;
        }
    }

    static int N, M, vers;
    static int[] inputArray;
    static Node[] treeVersion;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(br.readLine());
        inputArray = new int[N + 1];

        String[] str = br.readLine().split(" ");
        for(int i = 0; i < N; i++) {
            inputArray[i + 1] = Integer.parseInt(str[i]);
        }

        M = Integer.parseInt(br.readLine());
        treeVersion = new Node[M + 1];

        vers = 0;
        treeVersion[0] = makeTree(1, N);

        for(int i = 0; i < M; i++) {
            str = br.readLine().split(" ");
            int cmd = Integer.parseInt(str[0]);

            if(cmd == 1) {
                int idx = Integer.parseInt(str[1]);
                int k = Integer.parseInt(str[2]);

                treeVersion[++vers] = update(treeVersion[vers - 1], 1, N, idx, k);
            }
            else {
                int k = Integer.parseInt(str[1]);
                int a = Integer.parseInt(str[2]);
                int b = Integer.parseInt(str[3]);

                long ans = getSum(treeVersion[k], 1, N, a, b);
                sb.append(ans).append('\n');
            }
        }

        System.out.print(sb.toString());
    }

    // k번째 쿼리까지 적용된 a ~ b 구간합 (node : 이전 버전 노드)
    private static long getSum(Node node, int left, int right, int a, int b) {
        if(node == null) return 0;
        if(b < left || a > right) return 0;
        if(a <= left && b >= right) return node.sum;

        int mid = (left + right) / 2;
        return getSum(node.left, left, mid, a, b) + getSum(node.right, mid + 1, right, a, b);
    }

    // idx 노드를 k로 업데이트
    static Node update(Node prev, int left, int right, int idx, int k) {
        if(left == right) {
            return new Node(k, null, null);
        }

        int mid = (left + right) / 2;
        Node leftNode = prev.left;
        Node rightNode = prev.right;

        if(idx <= mid) {
            leftNode = update(prev.left, left, mid, idx, k);
        }
        else {
            rightNode = update(prev.right, mid + 1, right, idx, k);
        }

        return new Node(leftNode.sum + rightNode.sum, leftNode, rightNode);
    }

    // inputArray로 tree 생성
    static Node makeTree(int left, int right) {
        if(left == right) {
            return new Node(inputArray[left], null, null);
        }

        int mid = (left + right) / 2;
        Node leftNode = makeTree(left, mid);
        Node rightNode = makeTree(mid + 1, right);

        return new Node(leftNode.sum + rightNode.sum, leftNode, rightNode);
    }
}

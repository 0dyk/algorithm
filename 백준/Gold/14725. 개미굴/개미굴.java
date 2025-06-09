import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class Main {

    static int N;
    static Node ROOT_NODE;
    static StringBuilder sb;

    static class Node {
        Map<String, Node> child;

        public Node() {
            this.child = new TreeMap<>();
        }
    }

    static void insetNode (String[] str) {
        int k = Integer.parseInt(str[0]);

        Node cur = ROOT_NODE;

        for(int i = 1; i < k + 1; i++) {
            if(cur.child.containsKey(str[i])) {
                cur = cur.child.get(str[i]);
            }
            else {
                Node newNode = new Node();
                cur.child.put(str[i], newNode);
                cur = newNode;
            }
        }
    }

    static void printNode(Node node, int dep) {

        for(Map.Entry<String, Node> next : node.child.entrySet()) {
            String val = next.getKey();
            Node child = next.getValue();

            sb.append("--".repeat(dep)).append(val).append("\n");

            printNode(child, dep + 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        N = Integer.parseInt(br.readLine());
        ROOT_NODE = new Node();

        for (int i = 0; i < N; i++) {
            String[] str = br.readLine().split(" ");

            insetNode(str);
        }

        printNode(ROOT_NODE, 0);
        System.out.println(sb.toString());
    }
}
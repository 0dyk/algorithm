import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    static int N;
    static Node[][] nodes;
    static Edge[] xyzADJ;
    static int[] parent;

    static class Edge implements Comparable<Edge> {
        int a, b;
        int c;
        public Edge(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        @Override
        public int compareTo(Edge o) {
            return this.c - o.c;
        }
    }
    static class Node implements Comparable<Node> {
        int k;
        int idx;

        public Node(int k, int idx) {
            this.k = k;
            this.idx = idx;
        }

        @Override
        public int compareTo(Node o) {
            return this.k - o.k;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        nodes = new Node[3][N];
        xyzADJ = new Edge[(N - 1) * 3];
        parent = new int[N];

        for(int i = 0; i < N; ++i) {
            String[] input = br.readLine().split(" ");
            nodes[0][i] = new Node(Integer.parseInt(input[0]), i);
            nodes[1][i] = new Node(Integer.parseInt(input[1]), i);
            nodes[2][i] = new Node(Integer.parseInt(input[2]), i);
            parent[i] = i;
        }

        Arrays.sort(nodes[0]);
        Arrays.sort(nodes[1]);
        Arrays.sort(nodes[2]);

        for(int i = 0; i < N - 1; ++i) {
            xyzADJ[i] = new Edge(nodes[0][i].idx, nodes[0][i + 1].idx, Math.abs(nodes[0][i].k - nodes[0][i + 1].k));
            xyzADJ[N - 1 + i] = new Edge(nodes[1][i].idx, nodes[1][i + 1].idx, Math.abs(nodes[1][i].k - nodes[1][i + 1].k));
            xyzADJ[2 * (N - 1) + i] = new Edge(nodes[2][i].idx, nodes[2][i + 1].idx, Math.abs(nodes[2][i].k - nodes[2][i + 1].k));
        }

        Arrays.sort(xyzADJ);

        long answer = 0;

        for (Edge edge : xyzADJ) {
            if (union(edge.a, edge.b)) {
                answer += edge.c;
            }
        }

        System.out.println(answer);
    }

    static boolean union(int a, int b) {
        int fa = Find(a);
        int fb = Find(b);

        if(fa == fb) return false;

        parent[fb] = fa;
        return true;
    }

    static int Find(int x) {
        if(parent[x] == x) return x;
        else return parent[x] = Find(parent[x]);
    }
}
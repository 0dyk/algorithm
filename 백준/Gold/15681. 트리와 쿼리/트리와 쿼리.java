import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static ArrayList<Integer>[] adjList;
    static ArrayList<Integer>[] treeList;
    static int[] childNode;
    static boolean[] visited;

    static int make_tree(int sum, int parent) {
        sum++;

        visited[parent] = true;
        for(int i = 0; i < adjList[parent].size(); i++) {
            if (visited[adjList[parent].get(i)]) continue;

            treeList[parent].add(adjList[parent].get(i));
            sum += make_tree(0, adjList[parent].get(i));
        }

        childNode[parent] = sum;

        return sum;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();

        String[] input;
        input = br.readLine().split(" ");
        int N, Q, R;

        N = Integer.parseInt(input[0]);
        R = Integer.parseInt(input[1]);
        Q = Integer.parseInt(input[2]);

        childNode = new int[N + 1];
        visited = new boolean[N + 1];
        adjList = new ArrayList[N + 1];
        treeList = new ArrayList[N + 1];
        for(int i = 1; i <= N; ++i) {
            adjList[i] = new ArrayList<>();
            treeList[i] = new ArrayList<>();
        }

        int x, y;
        for(int i = 0; i < N - 1; ++i){
            input = br.readLine().split(" ");
            x = Integer.parseInt(input[0]);
            y = Integer.parseInt(input[1]);

            adjList[x].add(y);
            adjList[y].add(x);
        }

        // R이 루트
        make_tree(0, R);

        for(int i = 0; i < Q; ++i){
            sb.append(childNode[Integer.parseInt(br.readLine())]);
            sb.append("\n");
        }

        System.out.println(sb.toString());
    }
}
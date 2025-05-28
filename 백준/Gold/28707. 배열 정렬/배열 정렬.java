import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N, M, answer;
    static int[] arr;
    static List<Node> adjList;
    static Map<Long, Integer> minCost;

    static class Node {
        int x, y;
        int cost;

        public Node(int x, int y, int cost) {
            this.x = x;
            this.y = y;
            this.cost = cost;
        }
    }

    static class PqNode implements Comparable<PqNode> {
        Long state;
        int cost;

        public PqNode(Long state, int cost) {
            this.state = state;
            this.cost = cost;
        }

        @Override
        public int compareTo(PqNode o) {
            return Integer.compare(this.cost, o.cost);
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        solve();

        System.out.println(answer);
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        answer = 0;
        N = Integer.parseInt(br.readLine());
        minCost = new HashMap<>();
        adjList = new ArrayList<>();

        String[] str = br.readLine().split(" ");
        arr = Arrays.stream(str)
                .mapToInt(Integer::parseInt)
                .toArray();

        M = Integer.parseInt(br.readLine());
        for(int i = 0; i < M; i++) {
            str = br.readLine().split(" ");

            int l = Integer.parseInt(str[0]);
            int r = Integer.parseInt(str[1]);
            int c = Integer.parseInt(str[2]);

            adjList.add(new Node(l - 1, r - 1, c));
        }
    }
    static void solve() {

        // 현재 값, cost
        PriorityQueue<PqNode> pq = new PriorityQueue<>();
        long state = convertArrayToState(arr);
        minCost.put(state, 0);
        pq.add(new PqNode(state, 0));

        while (!pq.isEmpty()) {
            PqNode cur = pq.poll();

            for(Node node : adjList) {
                // 변경 의미 없음.
                if(getValue(cur.state, node.x) == getValue(cur.state, node.y)) continue;

                long nextState = swapValues(cur.state, node.x, node.y);
                int nextCost = cur.cost + node.cost;

                // 아직 방문 안함
                if(!minCost.containsKey(nextState)) {
                    minCost.put(nextState, nextCost);
                    pq.add(new PqNode(nextState, nextCost));
                }
                // 이미 방문했지만 + 돈이 덜 듬
                else if(minCost.containsKey(nextState) && nextCost < minCost.get(nextState)) {
                    minCost.put(nextState, nextCost);
                    pq.add(new PqNode(nextState, nextCost));
                }
            }
        }

        Arrays.sort(arr);
        long sortedState = convertArrayToState(arr);
        answer = minCost.getOrDefault(sortedState, -1);
    }

    static long convertArrayToState(int[] arr) {
        long state = 0L;
        for (int i = 0; i < arr.length; i++) {
            int val = arr[i];
            state |= ((long)val << (i * 4));
        }
        return state;
    }
    static int getValue(long state, int pos) {
        return (int)(state >> (pos * 4) & 15);
    }
    static long setValue(long state, int pos, int val) {
        long mask = 15L << (pos * 4);
        state &= ~mask;
        state |= ((long) val << (pos) * 4);
        return state;
    }
    static long swapValues(long state, int a, int b) {
        int valA = getValue(state, a);
        int valB = getValue(state, b);
        state = setValue(state, a, valB);
        state = setValue(state, b, valA);
        return state;
    }
}
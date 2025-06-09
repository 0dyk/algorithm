import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N, D;

    // 합쳐도 상관없음.
    static int[][] people;

    //
    static PriorityQueue<Integer> pq;

    public static void main(String[] args) throws IOException {
        input();
        solve();
    }

    static void solve() {
        int maxCount = 0;

        pq = new PriorityQueue<>();

        for(int[] node : people) {
            // node[0] :
            if(node[1] - node[0] > D) continue;

            // node[1] - D :
            while(!pq.isEmpty() && pq.peek() < node[1] - D) {
                pq.poll();
            }

            pq.offer(node[0]);

            if(pq.size() > maxCount) maxCount = pq.size();
        }

        System.out.println(maxCount);
    }

    static void input () throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        people = new int[N][2];

        for(int i = 0; i < N; i++) {
            String[] str = br.readLine().split(" ");
            int h = Integer.parseInt(str[0]);
            int o = Integer.parseInt(str[1]);

            if(h > o) {
                int tmp = h;
                h = o;
                o = tmp;
            }

            people[i][0] = h;
            people[i][1] = o;
        }

        Arrays.sort(people, (o1, o2) -> {
            if(o1[1] == o2[1]) return o1[0] - o2[0];
            return o1[1] - o2[1];
        });
        D = Integer.parseInt(br.readLine());
    }
}
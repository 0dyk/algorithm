import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

    static int N, M;
    static int[][] dist;

    static List<int[]> edges;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] str = br.readLine().split(" ");
        N = Integer.parseInt(str[0]);
        M = Integer.parseInt(str[1]);

        edges = new ArrayList<>();
        dist = new int[N + 1][N + 1];

        for(int i = 1; i < N + 1; i++) {
            for(int j = 1; j < N + 1; j++) {
                dist[i][j] = 101 * 20001;
            }
        }

        for(int i = 1; i < N + 1; i++) {
            dist[i][i] = 0;
        }

        for(int i = 0; i < M; i++) {
            str = br.readLine().split(" ");

            int s = Integer.parseInt(str[0]);
            int e = Integer.parseInt(str[1]);
            int l = Integer.parseInt(str[2]);

            edges.add(new int[] {s, e, l});

            dist[s][e] = Math.min(dist[s][e], l);
            dist[e][s] = Math.min(dist[e][s], l);
        }

        for(int k = 1; k < N + 1; k++) {
            for(int i = 1; i < N + 1; i++) {
                for(int j = 1; j < N + 1; j++) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        double answer = Double.MAX_VALUE;

        for(int s = 1; s < N + 1; s++) {
            double fireTime = 0.0;

            for(int[] edge : edges) {
                int t1 = dist[s][edge[0]];
                int t2 = dist[s][edge[1]];

                int dif = Math.abs(t1 - t2);

                double tmpTime = 0.0;
                if(dif >= edge[2]) {
                    tmpTime = Math.min(t1 + edge[2], t2 + edge[2]);
                }
                else {
                    tmpTime = Math.max(t1, t2) + (edge[2] - dif) / 2.0;
                }

                fireTime = Math.max(fireTime, tmpTime);
            }

            answer = Math.min(answer, fireTime);
        }

        System.out.printf("%.1f\n", answer);
    }
}

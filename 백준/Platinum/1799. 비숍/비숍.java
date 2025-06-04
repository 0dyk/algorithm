import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {

    static int N, digCount;
    static int[][] board;

    static int[][] dig1, dig2;
    static List<Integer>[] list;
    static boolean[] visited;
    static int[] match;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        digCount = 2 * N;
        board = new int[N][N];

        list = new ArrayList[digCount + 1];
        for(int i = 0; i < list.length; i++) {
            list[i] = new ArrayList<>();
        }

        visited = new boolean[digCount];
        match = new int[digCount];

        for (int i = 0; i < N; i++) {
            String[] str = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(str[j]);
            }
        }

        dig1 = new int[N][N];
        dig2 = new int[N][N];

        createDig();
        drawList();

        int answer = 0;
        Arrays.fill(match, -1);
        for(int i = 1; i < digCount; i++) {
            Arrays.fill(visited, false);

            if(matching(i)) {
                answer++;
            }
        }

        System.out.println(answer);
    }

    static void createDig() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dig1[i][j] = i + j + 1;
            }
        }

        int k = 1;
        for (int i = N - 1; i >= 0; i--) {
            for (int j = 0; j < N; j++) {
                dig2[i][j] = k + j;
            }
            k++;
        }
    }
    static void drawList() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(board[i][j] == 1) {
                    list[dig1[i][j]].add(dig2[i][j]);
                }
            }
        }
    }
    static boolean matching(int k) {
        for(int i = 0; i < list[k].size(); i++) {
            int cur = list[k].get(i);

            if(!visited[cur]) {
                visited[cur] = true;

                if(match[cur] == -1 || matching(match[cur])) {
                    match[cur] = k;
                    return true;
                }
            }
        }

        return false;
    }
}
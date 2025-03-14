import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int[][] dxdy = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    static int N, M;
    static int[][] board;

    static int DFS(int x, int y, int k) {
        int nx = x + dxdy[board[x][y]][0];
        int ny = y + dxdy[board[x][y]][1];

        board[x][y] = k;

        // 범위 밖으로 나감 -> 종료 및 1 리턴
        if(nx < 0 || nx >= N || ny < 0 || ny >= M) {
            return 1;
        }

        // 아직 탐색 안함
        else if(board[nx][ny] >= 0) {
            return DFS(nx, ny, k);
        }

        // 같은 그룹 (한바퀴 돔)
        else if(board[nx][ny] == k) {
            return 1;
        }

        // 다른 그룹
        // if(board[nx][ny] != k)
        else {
            return 0;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] s = br.readLine().split(" ");
        N = Integer.parseInt(s[0]);
        M = Integer.parseInt(s[1]);

        int idx = 0, answer = 0;
        board = new int[N][M];

        for(int i = 0; i < N; ++i) {
            String str = br.readLine();
            for(int j = 0; j < M; ++j) {
                if(str.charAt(j) == 'D') {
                    board[i][j] = 0;
                }
                else if(str.charAt(j) == 'U') {
                    board[i][j] = 1;
                }
                else if (str.charAt(j) == 'L') {
                    board[i][j] = 2;
                }
                else {
                    board[i][j] = 3;
                }
            }
        }

        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(board[i][j] >= 0) {
                    answer += DFS(i, j, --idx);
                }
            }
        }

        System.out.println(answer);
    }
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int N, maxValue;
    static int[][] board;
    static int[][] dxy = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        board = new int[N][N];

        for(int i = 0; i < N; i++) {
            String[] str = br.readLine().split(" ");
            for(int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(str[j]);
            }
        }

        int answer = 0;

        maxValue = 0;
        DFS(0, 0, 0);
        answer += maxValue;

        maxValue = 0;
        DFS(0, 1, 0);
        answer += maxValue;

        System.out.println(answer);
    }

    static void DFS(int x, int y, int cnt) {
        if (x == N) {
            if (cnt > maxValue) {
                maxValue  = cnt;
            }
            return;
        }

        // 남은 칸 개수 + cnt가 maxValue보다 작은 경우 return

        int nx = y + 2 >= N ? x + 1 : x;
        int ny = y + 2 >= N ? (y + 1) % 2 : y + 2;

        // 현재 자리에 놓을 수 있음?
        if(isPlace(x, y)) {
            board[x][y] = 2;
            DFS(nx, ny, cnt + 1);
            board[x][y] = 1;
        }

        DFS(nx, ny, cnt);
    }

    static boolean isPlace(int x, int y) {
        if(board[x][y] == 0) return false;

        for(int dir = 0; dir < 4; ++dir) {
            for(int k = 1; k < N; ++k) {
                int nx = x + dxy[dir][0] * k;
                int ny = y + dxy[dir][1] * k;

                if(!isBoundary(nx, ny)) {
                    break;
                }

                if(board[nx][ny] == 2) {
                    return false;
                }
            }
        }

        return true;
    }

    static boolean isBoundary(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N;
    }
}
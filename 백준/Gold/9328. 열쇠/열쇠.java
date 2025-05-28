import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br;

    static int TestCaseSize;
    static int H, W, answer;
    static char[][] board;
    static boolean[][] visited;
    static Queue<int []> q;
    static Door[] doors;
    static int[][] dxy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    static class Door {
        List<int []> xy = new ArrayList<>();
        boolean hasKey;

        public void init() {
            xy.clear();
            this.hasKey = false;
        }
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        board = new char[101][101];
        visited = new boolean[101][101];
        q = new ArrayDeque<>();
        doors = new Door[27];
        for(int i = 0; i < 27; ++i) doors[i] = new Door();

        TestCaseSize = Integer.parseInt(br.readLine());
        for(int t = 0; t < TestCaseSize; t++) {
            input();
            solve();
            System.out.println(answer);
        }
    }

    static void input() throws IOException {
        // init
        answer = 0;
        q.clear();
        for(int i = 0; i < 27; i++) doors[i].init();
        for(int i = 0; i < 101; i++) Arrays.fill(visited[i], false);

        // input
        String[] input = br.readLine().split(" ");
        H = Integer.parseInt(input[0]);
        W = Integer.parseInt(input[1]);

        for(int i = 0; i < H; i++) {
            String line = br.readLine();

            for(int j = 0; j < W; j++) {
                board[i][j] = line.charAt(j);

                if(isDoor(board[i][j])) {
                    doors[board[i][j] - 'A'].xy.add(new int[]{i, j});
                }
            }
        }

        String str = br.readLine();

        if(str.charAt(0) != '0') {
            for(int i = 0; i < str.length(); i++) {
                doors[str.charAt(i) - 'a'].hasKey = true;
            }
        }
    }

    static void solve() {
        // 테두리 체크
        for(int i = 0; i < H; i++) {
            move(i, 0);
            move(i, W - 1);
        }
        for(int j = 1; j < W - 1; j++) {
            move(0, j);
            move(H - 1, j);
        }

        // bfs
        while(!q.isEmpty()) {
            int x = q.peek()[0];
            int y = q.peek()[1];
            q.poll();

            for(int i = 0; i < 4; ++i) {
                int nx = x + dxy[i][0];
                int ny = y + dxy[i][1];

                // 범위
                if(!inRange(nx, ny)) continue;

                move(nx, ny);
            }
        }
    }

    static void move(int x, int y) {
        if(board[x][y] == '*' || visited[x][y]
                || isDoor(board[x][y]) && !doors[board[x][y] - 'A'].hasKey) {
            return;
        }

        visited[x][y] = true;
        q.offer(new int[]{x, y});

        if(board[x][y] == '$') {
            answer++;
        }

        if(isKey(board[x][y])) {
            doors[board[x][y] - 'a'].hasKey = true;

            for(int[] xy : doors[board[x][y] - 'a'].xy) {
                if(isCanMoved(xy[0], xy[1])) {
                    visited[xy[0]][xy[1]] = true;
                    q.offer(new int[] {xy[0], xy[1]});
                }
            }
        }
    }
    static boolean isDoor(char c) {
        return c >= 'A' && c <= 'Z';
    }
    static boolean isKey(char c) {
        return c >= 'a' && c <= 'z';
    }
    static boolean isCanMoved(int x, int y) {
        for(int i = 0; i < 4; ++i) {
            int nx = x + dxy[i][0];
            int ny = y + dxy[i][1];

            if(!inRange(nx, ny) || visited[nx][ny]) {
                return true;
            }
        }

        return false;
    }
    static boolean inRange (int x, int y) {
        return x >= 0 && y >= 0 && x < H && y < W;
    }
}
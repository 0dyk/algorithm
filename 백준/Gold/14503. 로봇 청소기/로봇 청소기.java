import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    // 0 ~ 3, 북 동 남 서
    static int[][] dxdy = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // input
        int N, M;
        int r, c, d;
        int[][] room;

        String[] str = br.readLine().split(" ");
        N = Integer.parseInt(str[0]);
        M = Integer.parseInt(str[1]);

        str = br.readLine().split(" ");
        r = Integer.parseInt(str[0]);
        c = Integer.parseInt(str[1]);
        d = Integer.parseInt(str[2]);

        room = new int[N][M];

        for(int i = 0; i < N; i++) {
            str = br.readLine().split(" ");
            for(int j = 0; j < M; j++) {
                room[i][j] = Integer.parseInt(str[j]);
            }
        }

        //
        int answer = 0;

        while(true) {
            if(room[r][c] == 0) {
                answer++;
                room[r][c] = -1;
            }

            boolean flag = false;

            for(int k = 0; k < 4; k++) {
                int nd = (d + 3 - k) % 4;
                int nr = r + dxdy[nd][0];
                int nc = c + dxdy[nd][1];

                if(room[nr][nc] == 0) {
                    flag = true;
                    r = nr;
                    c = nc;
                    d = nd;
                    break;
                }
            }

            if(flag) {
                continue;
            }
            else {
                r += dxdy[d ^ 2][0];
                c += dxdy[d ^ 2][1];

                if(room[r][c] == 1) {
                    break;
                }
            }
        }

        System.out.println(answer);
    }
}

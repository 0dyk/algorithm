import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    static int MOD = 1_000_000_007;
    // 정보과학관 / 전산관 / 미래관 / 신양관 / 한경직기념관 / 진리관 / 학생회관 / 형남공학관
    //    0         1       2       3         4         5        6         7
    static long [][] adj = {
            { 0, 1, 1, 0, 0, 0, 0, 0 },
            { 1, 0, 1, 1, 0, 0, 0, 0 },
            { 1, 1, 0, 1, 1, 0, 0, 0 },
            { 0, 1, 1, 0, 1, 1, 0, 0 },
            { 0, 0, 1, 1, 0, 1, 0, 1 },
            { 0, 0, 0, 1, 1, 0, 1, 0 },
            { 0, 0, 0, 0, 0, 1, 0, 1 },
            { 0, 0, 0, 0, 1, 0, 1, 0 }
    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int D = Integer.parseInt(br.readLine());

        long[][] answer = new long[8][8];
        for(int i = 0; i < 8; ++i) answer[i][i] = 1;

        while(D > 0) {
            if((D & 1) == 1) {
                answer = multiply(answer, adj);
            }

            adj = multiply(adj, adj);
            D >>= 1;
        }

        System.out.println(answer[0][0]);
    }

    static long[][] multiply (long[][]a, long[][] b) {
        long[][] c = new long[8][8];

        for(int i = 0; i < 8; ++i) {
            for(int j = 0; j < 8; ++j) {
                for(int k = 0; k < 8; ++k) {
                    c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
                }
            }
        }

        return c;
    }
}
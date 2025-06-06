import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int N;
    static int[][] combi;

    static final int MOD = 10_007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        combi = new int[53][53];

        for(int i = 0; i < 53; i++) {
            combi[i][0] = 1;
        }

        // aCb = a-1Cb + a-1Cb-1
        for(int i = 1; i <= 52; i++) {
            for(int j = 1; j <= i; j++) {
                combi[i][j] = (combi[i - 1][j - 1] + combi[i - 1][j]) % MOD;
            }
        }

        int answer = 0;

        for(int i = 1; i <= 13 && N - 4 * i >= 0; i++) {
            if(i % 2 == 1) answer += combi[52 - 4 * i][N - 4 * i] * combi[13][i];
            else answer -= combi[52- 4 * i][N - 4 * i] * combi[13][i];

            answer %= MOD;
        }

        if(answer < 0) answer += MOD;

        System.out.println(answer);
    }
}
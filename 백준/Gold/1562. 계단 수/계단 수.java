import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[][][] dp = new int [N + 1][10][1024];

        for(int i = 1; i <= 9; ++i) {
            dp[1][i][1 << i] = 1;
        }

        // 자리수.
        for(int i = 1; i < N; ++i) {
            // 끝자리 수.
            for(int j = 0; j <= 9; ++j) {
                int a = (j + 1);
                int b = (j - 1);
                // 값은?
                for(int k = 1; k <= 1023; ++k) {
                    // i -> i+1

                    // 현재값 : dp[i][j][k] -> 이게 갈 수 있는 곳은?

                    if(a != 10) dp[i + 1][a][k | (1 << a)] = (dp[i + 1][a][k | (1 << a)] + dp[i][j][k]) % 1000000000;
                    if(b != -1) dp[i + 1][b][k | (1 << b)] = (dp[i + 1][b][k | (1 << b)] + dp[i][j][k]) % 1000000000;
                }
            }
        }

        int answer = 0;
        for(int i = 0; i <= 9; ++i) {
            answer = (answer + dp[N][i][1023]) % 1000000000;
        }

        System.out.println(answer);
    }
}

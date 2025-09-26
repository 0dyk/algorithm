import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    static int C, N;
    static int[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int answer = Integer.MAX_VALUE;

        String[] str = br.readLine().split(" ");

        C = Integer.parseInt(str[0]);
        N = Integer.parseInt(str[1]);


        dp = new int[C + 100];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;

        for(int i = 0; i < N; i++) {
            str = br.readLine().split(" ");

            int cost = Integer.parseInt(str[0]);
            int person = Integer.parseInt(str[1]);

            for(int k = person; k < C + 100; k++) {
                if(dp[k - person] != Integer.MAX_VALUE) {
                    dp[k] = Math.min(dp[k], dp[k - person] + cost);
                }
            }
        }

        for(int i = C; i < C + 100; i++) {
            if(answer > dp[i]) answer = dp[i];
        }

        System.out.println(answer);
    }
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static boolean[][] palindrome;
    static int[] dp;
    static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();

        N = input.length();

        // i ~ j
        palindrome = new boolean[N + 1][N + 1];
        dp = new int[N + 1];

        for(int i = 0; i < N; ++i) {
            palindrome[i][i] = true;
        }
        for(int i = 0; i < N - 1; ++i) {
            if(input.charAt(i) == input.charAt(i + 1)) {
                palindrome[i][i + 1] = true;
            }
        }

        // i : idx, j : size
        for(int j = 3; j <= N; ++j) {
            for(int i = 0; i + j - 1 < N; ++i) {
                // 이전 사이즈 가능 + 지금도 가능
                if(palindrome[i + 1][i + j - 2] && (input.charAt(i) == input.charAt(i + j - 1))) {
                    palindrome[i][i + j - 1] = true;
                }
            }
        }

        //
        for (int i = 0; i < N; ++i) {
            if (palindrome[0][i]) {
                dp[i] = 0;
            } 
            else {
                dp[i] = Integer.MAX_VALUE;
                for (int j = 0; j < i; ++j) {
                    if (palindrome[j + 1][i]) {
                        dp[i] = Math.min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        System.out.println(dp[N - 1] + 1);
    }
}
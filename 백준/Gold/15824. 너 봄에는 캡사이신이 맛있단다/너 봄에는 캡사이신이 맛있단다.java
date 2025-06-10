import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    static int N;
    static int[] arr;
    static int[] powerOfTwo;
    static int MOD = 1_000_000_007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        powerOfTwo = new int[N];

        String[] str = br.readLine().split(" ");
        for(int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(str[i]);
        }

        Arrays.sort(arr);

        powerOfTwo[0] = 1;
        for(int i = 1; i < N; i++) {
            powerOfTwo[i] = powerOfTwo[i - 1] * 2 % MOD;
        }

        long answer = 0;

        for(int i = 0; i < N; i++) {
            // 나보다 작은 놈들 i 개
            answer = (answer + ((long) arr[i] * powerOfTwo[i]) % MOD) % MOD;

            // 나보다 큰 놈들 N - i - 1 개
            answer = (answer - ((long) arr[i] * powerOfTwo[N - i - 1]) % MOD + MOD) % MOD;
        }

        System.out.println(answer);
    }
}
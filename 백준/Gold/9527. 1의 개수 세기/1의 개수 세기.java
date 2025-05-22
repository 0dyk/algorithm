import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static final int MAX = 55;
    static long[] prefix_sum = new long[56];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        long A = Long.parseLong(input[0]);
        long B = Long.parseLong(input[1]);

        prefix_sum[0] = 1;

        for(int i = 1; i < MAX; i++) {
            prefix_sum[i] = prefix_sum[i - 1] * 2 + (1L << i);
        }

        long answer = fx(B) - fx(A - 1);

        System.out.println(answer);
    }

    public static long fx(long x) {
        long ret = x & 1;

        for(int i = MAX - 1; i > 0; i--) {
            long k = 1L << i;

            if((x & k) != 0) {
                x -= k;
                ret += prefix_sum[i - 1] + x + 1;
            }
        }

        return ret;
    }
}
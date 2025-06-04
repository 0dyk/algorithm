import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int N;

    static int[] arr;
    static int[] dp;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        arr = new int[501];
        dp = new int[501];

        for(int i = 0; i < N; i++) {
            String[] str = br.readLine().split(" ");
            arr[Integer.parseInt(str[0])] = Integer.parseInt(str[1]);
        }

        int sz = 0;
        dp[0] = arr[0];

        for(int i = 1; i < 501; ++i) {
            if(dp[sz] < arr[i]) {
                dp[sz + 1] = arr[i];
                sz++;
            }
            else {
                int k = binarySearch(0, sz, arr[i]);
                dp[k] = arr[i];
            }
        }

        System.out.println(N - sz);
    }

    private static int binarySearch(int left, int right, int k) {
        while(left < right) {
            int mid = (left + right) / 2;

            if(dp[mid] < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return right;
    }
}
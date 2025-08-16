import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int sha = 0;
        long[] arr = new long[10];

        int pos = 1;

        while(pos <= N) {
            int left = N / (pos * 10);
            int cur = (N / pos) % 10;
            int right = N % pos;

            for (int i = 0; i <= 9; i++) {
                if(i == 0) arr[i] += (long) (left - 1) * pos;
                else arr[i] += (long) left * pos;

                if (cur > i) arr[i] += pos;
                else if (cur == i) arr[i] += right + 1;
            }

            pos *= 10;
        }

        for(int i = 0; i <= 9; ++i) {
            System.out.print(arr[i] + (i < 9 ? " " : "\n"));
        }
    }
}
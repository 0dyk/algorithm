import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int[][] ABCDArray = new int[4001][4];

    public static void main(String[] args) throws IOException {

        // 12s, 1025mb, 1 <= n <= 4000

        // DP, 이분탐색, 투포인터...

        // input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        for(int i = 0; i < N; ++i) {
            String[] s = br.readLine().split(" ");

            ABCDArray[i][0] = Integer.parseInt(s[0]);
            ABCDArray[i][1] = Integer.parseInt(s[1]);
            ABCDArray[i][2] = Integer.parseInt(s[2]);
            ABCDArray[i][3] = Integer.parseInt(s[3]);
        }

        //
        int[] ABArray = new int[N * N];
        int[] CDArray = new int[N * N];

        int idx = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                ABArray[idx] = (ABCDArray[i][0] + ABCDArray[j][1]);
                CDArray[idx] = (ABCDArray[i][2] + ABCDArray[j][3]);
                idx++;
            }
        }

        Arrays.sort(ABArray);
        Arrays.sort(CDArray);
        int tmp;
        for(int i = 0; i < CDArray.length / 2; ++i) {
            tmp = CDArray[i];
            CDArray[i] = CDArray[CDArray.length - 1 - i];
            CDArray[CDArray.length - 1 - i] = tmp;
        }

        long answer = 0;

        int ABIdx = 0;
        int CDIdx = 0;

        while(ABIdx < N * N && CDIdx < N * N) {
            int sum = ABArray[ABIdx] + CDArray[CDIdx];

            if (sum == 0) {
                long ABCount = 1;
                long CDCount = 1;

                while (ABIdx < N * N - 1 && ABArray[ABIdx] == ABArray[ABIdx + 1]) {
                    ABCount++;
                    ABIdx++;
                }

                while (CDIdx < N * N - 1 && CDArray[CDIdx] == CDArray[CDIdx + 1]) {
                    CDCount++;
                    CDIdx++;
                }

                ABIdx++;
                CDIdx++;

                answer += ABCount * CDCount;
            }
            else if (sum > 0) {
                CDIdx++;
            }
            else {
                ABIdx++;
            }
        }

        System.out.println(answer);
    }
}

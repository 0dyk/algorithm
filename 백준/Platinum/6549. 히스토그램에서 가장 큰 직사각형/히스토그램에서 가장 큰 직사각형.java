import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int[] num = new int[100001];

        while (true) {
            String[] str = br.readLine().split(" ");

            if(str.length == 1 && str[0].equals("0")) {
                break;
            }

            int N = Integer.parseInt(str[0]);

            for(int i = 1; i <= N; i++) {
                num[i] = Integer.parseInt(str[i]);
            }

            Stack<Integer> st = new Stack<>();

            long maxArea = 0;

            for(int i = 1; i <= N; i++) {
                while(!st.isEmpty() && num[st.peek()] > num[i]) {
                    int topIdx = st.pop();

                    // st가 비워져 있다 -> 앞에 놈들 다 나보다 크다. -> i - 1 (i는 안들어 가므로)
                    int width = st.isEmpty() ? i - 1 : i - st.peek() - 1;
                    long tmpArea = (long) num[topIdx] * width;

                    if(tmpArea > maxArea) {
                        maxArea = tmpArea;
                    }
                }

                st.push(i);
            }

            while(!st.isEmpty()) {
                int topIdx = st.pop();

                int width = st.isEmpty() ? N : N - st.peek();
                long tmpArea = (long) num[topIdx] * width;

                if(tmpArea > maxArea) {
                    maxArea = tmpArea;
                }
            }

            sb.append(maxArea).append('\n');
        }

        System.out.print(sb.toString());
    }
}


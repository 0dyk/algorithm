import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    static int[] arr;
    static int[] ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        arr = new int[N];
        ans = new int[N];

        String[] str = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(str[i]);
        }

        Stack<Integer> st = new Stack<>();

        for(int i = 0; i < N; i++) {
            while(!st.isEmpty() && arr[st.peek()] < arr[i]) {
                ans[st.pop()] = arr[i];
            }
            st.push(i);
        }

        while(!st.isEmpty()) {
            ans[st.pop()] = -1;
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < N; i++) {
            sb.append(ans[i]).append(" ");
        }
        System.out.println(sb);
    }
}

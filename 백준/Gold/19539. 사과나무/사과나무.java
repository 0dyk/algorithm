import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Iterator;

public class Main {
	static StringBuilder sb = new StringBuilder();
	static int N;
	static int[] arr;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		arr = new int[N];
		String[] str = br.readLine().split(" ");
		
		int sum = 0, cnt = 0;
		for(int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(str[i]);
			sum += arr[i];
			cnt += arr[i] / 2;
		}
		
		if(sum % 3 == 0 && cnt >= sum / 3) {
			sb.append("YES");
		}else {
			sb.append("NO");
		}
		
		sb.append("\n");

		System.out.println(sb);
	}
}
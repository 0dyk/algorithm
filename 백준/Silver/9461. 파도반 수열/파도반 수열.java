import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		long DP[] = new long[101];
		DP[1] = 1;
		DP[2] = 1;
		DP[3] = 1;
		for(int i=4; i<=100; i++) {
			DP[i] = DP[i-2] + DP[i-3];
		}
		
		int T = Integer.parseInt(in.readLine());
		for(int tc=1; tc<=T; tc++) {
			int N = Integer.parseInt(in.readLine());
			sb.append(DP[N]).append("\n");
		}
		System.out.println(sb.toString());
	}
}
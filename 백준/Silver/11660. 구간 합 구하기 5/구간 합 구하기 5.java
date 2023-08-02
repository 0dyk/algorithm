import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static int N, M;
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] str = br.readLine().split(" ");
		N = Integer.parseInt(str[0]);
		M = Integer.parseInt(str[1]);
		
		int[][] arr = new int[N+1][N+1];
		int[][] brr = new int[N+1][N+1];
		
		for(int i = 1; i <= N; i++) {
			str = br.readLine().split(" ");
			for(int j = 1; j <= N; j++) {
				arr[i][j] = Integer.parseInt(str[j-1]);
				brr[i][j] = brr[i-1][j] + brr[i][j-1] - brr[i-1][j-1] + arr[i][j];
			} //end for:j
			for(int j = 1; j <= N; j++) {
				
			}
		} //end for:i
		
		int x1, y1, x2, y2, ans;
		for(int i = 0; i < M; i++) {
			str = br.readLine().split(" ");
			x1 = Integer.parseInt(str[0]);
			y1 = Integer.parseInt(str[1]);
			x2 = Integer.parseInt(str[2]);
			y2 = Integer.parseInt(str[3]);
			
			ans = brr[x2][y2] - brr[x1-1][y2] - brr[x2][y1-1] +brr[x1-1][y1-1];
			sb.append(ans).append("\n");
		} //end for:i
		System.out.println(sb);
	} //end main

}
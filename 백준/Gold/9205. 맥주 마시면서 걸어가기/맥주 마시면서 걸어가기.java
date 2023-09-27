import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

	// 편의점 수
	static int N;
	
	// 집 좌표
	static int hx, hy;
	
	// 편의점 배열 좌표
	static List<int[]> arr;
	
	// 락 페스티벌 좌표
	static int ex, ey;
	
	// dp
	static int[][] dp;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; tc++) {
			N = Integer.parseInt(br.readLine());
			
			arr = new ArrayList<>();
			dp = new int[N + 2][N + 2];
			
			for(int i = 0; i < N+2; i++) {
				for(int j = 0; j< N+2; j++) {
					if(i != j) dp[i][j] = Integer.MAX_VALUE;
				}
			}
			
			int a, b;
			String[] str;
			for(int i = 0; i < N + 2; i++) {
				str = br.readLine().split(" ");
				a = Integer.parseInt(str[0]);
				b = Integer.parseInt(str[1]);
				arr.add(new int[] {a, b});
			}
			// 0 : 출발지
			// arr.size() - 1 : 도착지
			
			for(int i = 0; i < N+2; i++) {
				for(int j = 0; j< N+2; j++) {
					if(i != j) dp[i][j] = Integer.MAX_VALUE;
				}
			}
			
			// i -> j로 갈 수 있으면 0, 아니면 1
			for(int i = 0; i < N+1; i++) {
				for(int j = 1; j < N+2; j++) {
					if(i == j) continue;
					
					int dist = Math.abs(arr.get(i)[0] - arr.get(j)[0])
								+ Math.abs(arr.get(i)[1] - arr.get(j)[1]);
					
					if(dist <= 50 * 20) dp[i][j] = 0;
				}
			}
						
			// 경유지
			for(int i = 0; i < N + 2; i++) {
				// 출발지
				for(int j = 0; j < N + 2; j++) {
					// 출발지 == 경유지인 경유
					if(i == j) continue;
					
					for(int k = 0; k < N + 2; k++) {
						// 도착지와 출 or 경이 같은 경우
						if(i == k || j == k) continue;
						
						// 출발지에서 도착지로 가는 거리보다 출 -> 경 -> 도가 짧은 경우
						if(dp[j][i] == 0 && 0 == dp[i][k]) {
							dp[j][k] = dp[j][i] + dp[i][k];
						}
					}
				}
			} //end::for
			
			if(dp[0][N+1] == Integer.MAX_VALUE) {	
				System.out.println("sad");
			}else {
				System.out.println("happy");
			}
		} //end::tc
		
		
		
	}
	
	
	
	
}
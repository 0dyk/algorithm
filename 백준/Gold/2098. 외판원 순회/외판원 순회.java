import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	static int N;
	
	static int finish;

	static final int INF = 1987564321;
	
	static int[][] arr;
	
	// 현재 위치, 방문
	static int[][] dp;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		
		finish = (1 << N) - 1;
		arr = new int[N][N];
		dp = new int[N][finish];
		
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < finish; j++) {
				dp[i][j] = -1;
			}
		}
		
		
		String[] str;
		for(int i = 0; i < N; i++) {
			str = br.readLine().split(" " );
			for(int j = 0; j < N; j++) {
				arr[i][j] = Integer.parseInt(str[j]);
			}
		}
		
		int res = tsp(0, 1);
		
		System.out.println(res);
	}

	private static int tsp(int x, int check) {
		// 모든 도시 방문
		if(check == finish) {
			// 경로 없음면
			if(arr[x][0] == 0) return INF;
			// 경로 있으면
			else return arr[x][0];
		}
		
		// 이미 방문한 도시
		if(dp[x][check] != -1) return dp[x][check];

		// 방문
		dp[x][check] = INF;
		
		for(int i = 0; i < N; i++) {
			// i도시 방문
			int nx = check | (1 << i);
			
			// 경로가 없거나 이미 방문한 도시면 패스
			if(arr[x][i] == 0 || (check & (1 << i)) != 0) continue;
	
			// 갱신
			dp[x][check] = Math.min(dp[x][check], tsp(i, nx) + arr[x][i]);
		}
		
		return dp[x][check];
	}
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 행렬의 곱 너무 어렵스무니다...

public class Main {
	static StringBuilder sb = new StringBuilder();
	
	static long[] pado;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; ++tc) {
			// 초기화
			long[][] res = {{1,0,0},{0,1,0},{0,0,1}};
			long[][] arr = {{0,1,1},{1,0,0},{0,1,0}};
			
			long N = Long.parseLong(br.readLine());
			
			if(N <= 3) {
				sb.append(1 + "\n");
			}else {
				while(N >= 1) {
					if(N % 2 == 1) {
						res = gob(res, arr);
					}
					arr = gob(arr, arr);
					N /= 2;
				}
				
				sb.append(res[0][1] + "\n");;
			}
		}
		
		System.out.println(sb);
	}

	// 행렬의 곱
	private static long[][] gob(long[][] a, long[][] b) {
		long[][] tmp = new long[3][3];
		
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				for(int k = 0; k <3 ; k++) {
					tmp[i][j] += a[i][k] * b[k][j];
				}
				tmp[i][j] %= 998244353;
			}
		}
		
		return tmp;
	}
}
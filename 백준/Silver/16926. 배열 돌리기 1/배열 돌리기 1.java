import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	static StringBuilder sb = new StringBuilder();
	static int N, M, R;
	static int[][] arr;

	static public void solve() {
		int x = N, y = M;
		int nx = x, ny = y;
						
		for(;x >= 2 && y >= 2;) {
			int size = 2 * (x + y) - 4;
			
			for(int t = 0; t < R % size; t++) {	// R & size 만큼 회전
				int tmp = arr[nx - 1][ny - 1];
				for (int j = 0; j < y - 1; j++)
					arr[nx - 1][ny - 1 - j] = arr[nx - 1][ny - 2 - j];
				for (int j = 0; j < x - 1; j++)
					arr[nx - 1 - j][M - ny] = arr[nx - 2 - j][M - ny];
				for (int j = 0; j < y - 1; j++)
					arr[N - nx][M - ny + j] = arr[N - nx][M - ny + 1 + j];
				for (int j = 0; j < x - 2; j++)
					arr[N - nx + j][ny - 1] = arr[N - nx + 1 + j][ny - 1];
				arr[nx - 2][ny - 1] = tmp;
			}
			
			x -= 2; y -= 2;
			nx--; ny--;
		}
	}
	
	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String[] str = br.readLine().split(" ");
		N = Integer.parseInt(str[0]);
		M = Integer.parseInt(str[1]);
		R = Integer.parseInt(str[2]);

		arr = new int[N][M];
		for (int i = 0; i < N; i++) {
			str = br.readLine().split(" ");
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(str[j]);
			}
		}
		
		solve();
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sb.append(arr[i][j]);
				if (j != M - 1)
					sb.append(" ");
				else
					sb.append("\n");
			}
		}
		
		System.out.println(sb);

	}

}
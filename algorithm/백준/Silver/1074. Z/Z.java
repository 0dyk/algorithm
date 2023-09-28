import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	static StringBuilder sb = new StringBuilder();
	static int N, R, C, cnt;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String[] str = br.readLine().split(" ");
		N = Integer.parseInt(str[0]);
		R = Integer.parseInt(str[1]);
		C = Integer.parseInt(str[2]);

		cnt = 0;
		solve(0, 0, 1 << N);

		System.out.println(cnt);
	}

	private static void solve(int r, int c, int size) {		
		if(r == R && c == C) return;
		
		if (R < r + size / 2 && C < c + size / 2) {
			solve(r, c, size / 2);
		}
		else if (R < r + size / 2 && C >= c + size / 2) {
			cnt += ( size / 2 * size / 2);			
			solve(r, c + size / 2, size / 2);
		}
		else if (R >= r + size / 2 && C < c + size / 2) {
			cnt += 2 * ( size / 2 * size / 2);
			solve(r + size / 2, c, size / 2);
		}
		else if (R >= r + size / 2 && C >= c + size / 2) {
			cnt += 3 * ( size / 2 * size / 2);
			solve(r + size / 2, c + size / 2, size / 2);
		}
	}

}
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	static StringBuilder sb = new StringBuilder();
	static int N, R, C, cnt, res;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String[] str = br.readLine().split(" ");
		N = Integer.parseInt(str[0]);
		R = Integer.parseInt(str[1]);
		C = Integer.parseInt(str[2]);

		cnt = 0; res = 0;
		int size = (int) Math.pow(2, N);
		solve(0, 0, size);

		System.out.println(res);
	}

	private static void solve(int r, int c, int size) {		
		if(size == 1) {
			if(r == R && c == C) {
				res = cnt;
			}
			return;
		}

		
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
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;

public class Main {

	static StringBuilder sb = new StringBuilder();
	static int N;
	static int[][] arr;
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		N = Integer.parseInt(br.readLine());
		arr = new int[N][N];
		
		for(int i = 0; i < N; i++) {
			String str = br.readLine();
			for(int j = 0; j < N; j++) {
				arr[i][j] = (int)(str.charAt(j) - '0');
			}
		}
		
		search(0, 0, N);
	
		System.out.println(sb);
	}
	
	private static void search(int x, int y, int size) {
		if(check(x, y, size)) {
			sb.append(arr[x][y]);
			return;
		}
			
		sb.append("(");	
		search(x, y, size / 2);
		search(x, y + size / 2, size / 2);
		search(x + size / 2, y, size / 2);
		search(x + size / 2, y + size / 2, size / 2);
		sb.append(")");
	}
	
	private static boolean check(int x, int y, int size) {
		int sum = 0;
		for(int i = x; i < x + size; i++) {
			for(int j = y; j < y + size; j++) {
				sum += arr[i][j];
			}
		}
		
		if(sum == 0 || sum == size * size) return true;
		else return false;
	}
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
	
	static StringBuilder sb = new StringBuilder();
	
	static int[][] arr;
	static List<int []> blank;
	static boolean maked;
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		arr = new int[9][9];
		blank = new ArrayList<>();
		
		for(int i = 0; i < 9; i++) {
			String str = br.readLine();
			for(int j = 0; j< 9; j++) {
				arr[i][j] = str.charAt(j) - '0';
			
				if(arr[i][j] == 0) {
					blank.add(new int[] {i, j});
				}
			}
		}
		
		maked = false;
		dfs(0);		
	}

	// cnt번째  blank 체크 중
	private static void dfs(int cnt) {
		if(maked) return;
		
		if(cnt == blank.size()) {
			for(int i = 0; i < 9; i++) {
				for(int j = 0; j< 9; j++) {
					sb.append(arr[i][j]);
					if(j == 8)sb.append("\n");
				}
			}
			System.out.println(sb);
			maked = true;
			
			return;
		}

		boolean[] check = new boolean[10];
		
		int x = blank.get(cnt)[0], y = blank.get(cnt)[1];
		
		for(int i = 0; i < 9; i++) {
			check[arr[i][y]] = true;
			check[arr[x][i]] = true;
		}
		
		for(int i = x - x % 3; i < x - x % 3 + 3; i++) {
			for(int j = y - y % 3; j < y - y % 3 + 3; j++) {
				check[arr[i][j]]= true;
			}
		}
		
		for(int i = 1; i <= 9; i++) {	
			if(!check[i]) {
				arr[x][y] = i;
				dfs(cnt + 1);
				
				// 굳이 안해도 되긴 함
				arr[x][y] = 0;
			}
		}
	}
	
}
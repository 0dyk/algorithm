import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

public class Main {

	static StringBuilder sb = new StringBuilder();
	static int[][] arr;
	static boolean[][] visited;
	static boolean can;
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		arr = new int[6][3];
		visited = new boolean[6][6];
		
		for(int test_case = 1; test_case <= 4; test_case++) {
			String[] str = br.readLine().split(" ");
			
			for(int i = 0; i < 6; i++) {
				for(int j = 0; j < 3; j++) {
					arr[i][j] = Integer.parseInt(str[i*3 + j]);
				}
			}
			
			can = false;
			Search(0, 1);
			
			int res = 0;
			if(can) res = 1;
			
			sb.append(res).append(" ");
		}
		

		
		System.out.println(sb);
	}
	
	private static void Search(int left, int right) {
		if(left == 5) {
			boolean check = true;;
			for(int i = 0; i < 6; i++) {
				for(int j = 0; j < 3; j++) {
					if(arr[i][j] != 0) check = false;
				}
			}
			
			if(check) can = true;
			
			return;
		}
		
		// left win
		if(arr[left][0] > 0 && arr[right][2] > 0) {			
			arr[left][0]--;
			arr[right][2]--;
			
			if(right != 5) Search(left, right + 1);
			else Search(left + 1, left + 2);
			
			arr[left][0]++;
			arr[right][2]++;
		}
		// right win
		if(arr[left][2] > 0 && arr[right][0] > 0) {			
			arr[left][2]--;
			arr[right][0]--;
			
			if(right != 5) Search(left, right + 1);
			else Search(left + 1, left + 2);
			
			arr[left][2]++;
			arr[right][0]++;
		}
		// draw
		if(arr[left][1] > 0 && arr[right][1] > 0) {			
			arr[left][1]--;
			arr[right][1]--;
			
			if(right != 5) Search(left, right + 1);
			else Search(left + 1, left + 2);
			
			arr[left][1]++;
			arr[right][1]++;
		}		
		// 어렵다고요!
	}
}
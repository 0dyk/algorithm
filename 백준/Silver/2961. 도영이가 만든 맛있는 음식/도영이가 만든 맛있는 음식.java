import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static StringBuilder sb = new StringBuilder();
	static int N, input[][], res;
	static boolean isSelected[];
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		input = new int[N+1][2];
		isSelected = new boolean[N+1];
		res = Integer.MAX_VALUE;
		
		for(int i = 0; i < N; i++) {
			String[] str = br.readLine().split(" ");			
			input[i][0] = Integer.parseInt(str[0]);
			input[i][1] = Integer.parseInt(str[1]);
		}	
		
		// 고른 개수, 신맛,  쓴맛
		generateSubset(0, 1, 0, 0);
		
		System.out.println(res);
	}
	
	
	private static void generateSubset(int cnt, int sin, int ssn, int fcnt) {
		if(fcnt != 0 && Math.abs(sin - ssn) < res) {
			res = Math.abs(sin - ssn);
		}
		
		if (cnt == N) {
			return;
		}
		
		isSelected[cnt] = true;
		generateSubset(cnt + 1, sin * input[cnt][0], ssn + input[cnt][1], fcnt + 1);
		isSelected[cnt] = false;
		generateSubset(cnt + 1, sin, ssn, fcnt);
	}
	
}
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Iterator;

public class Main {
	static StringBuilder sb = new StringBuilder();
	static int N;
	static int[][] arr;
	
	public static void main(String[] args) throws Exception {	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++) {
			N = Integer.parseInt(br.readLine());
			
			int maxIncome = 0;			
			int preA = 0, preB = 0, preC = 0;
			for(int i = 0; i < N; i++) {
				String[] str = br.readLine().split(" ");
				
				int income = Math.max(Integer.parseInt(str[0]), Integer.parseInt(str[1]));
				income = Math.max(income, Integer.parseInt(str[2]));
			
				if(income > 0) maxIncome += income;
			}
			
			sb.append(maxIncome).append("\n");
		}
		System.out.println(sb);
	}
}
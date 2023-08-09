import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static StringBuilder sb = new StringBuilder();
	static int[][] arr;

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		arr = new int[100][100];
		int N = Integer.parseInt(br.readLine());
		for(int n = 0; n < N; n++) {
			String[] str = br.readLine().split(" ");
			int A = Integer.parseInt(str[0]);
			int B = Integer.parseInt(str[1]);
			
			for(int i = A; i < A + 10; i++) {
				for(int j = B; j < B + 10; j++) {
					arr[i][j]++;
				}
			}
		}
		
		int sum = 0;
		for(int i = 0; i < 100; i++) {
			for(int j = 0; j < 100; j++) {
				if(arr[i][j] != 0) sum++;
			}
		}
		
		System.out.println(sum);
	}
}
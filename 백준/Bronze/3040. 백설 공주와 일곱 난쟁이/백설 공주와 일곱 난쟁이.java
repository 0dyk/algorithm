import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	static StringBuilder sb = new StringBuilder();
	static int[] arr;
	static int sum;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		arr = new int[9];
		for (int i = 0; i < 9; i++) {
			arr[i] = Integer.parseInt(br.readLine());
			sum += arr[i];
		}

		sum -= 100;
		
		for(int i = 0; i < 8; i++) {
			for(int j = i + 1; j < 9; j++) {
				if(arr[i] + arr[j] == sum) {
					arr[i] = 100;
					arr[j] = 100;
				}
			}
		}
		
		for(int i = 0; i < 9; i++) {
			if(arr[i] != 100) sb.append(arr[i]).append("\n");
		}
		
		System.out.println(sb);
	}

}

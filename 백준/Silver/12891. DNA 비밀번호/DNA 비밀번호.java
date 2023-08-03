import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static StringBuilder sb = new StringBuilder();
	static int S, P;
	static int arr[] = {0,0,0,0};	// A C G T 의 개수
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		String[] str = br.readLine().split(" ");
		S = Integer.parseInt(str[0]);
		P = Integer.parseInt(str[1]);
		
		String pw = br.readLine();
		
		String[] s = br.readLine().split(" ");
		for(int i = 0; i < 4; i++) {
			arr[i] = Integer.parseInt(s[i]);
		}
		
		char[] res = new char[S];
		for(int i = 0; i < S; i++) {
			res[i] = pw.charAt(i);
		}
		
		int brr[] = {0,0,0,0};
		for(int i = 0; i < P; i++) {
			if(res[i] == 'A') brr[0]++;
			if(res[i] == 'C') brr[1]++;
			if(res[i] == 'G') brr[2]++;
			if(res[i] == 'T') brr[3]++;
		}
		int ans = 0;
		if(arr[0] <= brr[0] && arr[1] <= brr[1] && arr[2] <= brr[2] && arr[3] <= brr[3]) ans++;

		for(int i = P; i < S; i++) {
			if(res[i] == 'A') brr[0]++;
			else if(res[i] == 'C') brr[1]++;
			else if(res[i] == 'G') brr[2]++;
			else if(res[i] == 'T') brr[3]++;
			
			if(res[i-P] == 'A') brr[0]--;
			else if(res[i-P] == 'C') brr[1]--;
			else if(res[i-P] == 'G') brr[2]--;
			else if(res[i-P] == 'T') brr[3]--;

			if(arr[0] <= brr[0] && arr[1] <= brr[1] && arr[2] <= brr[2] && arr[3] <= brr[3]) ans++;
		}
		System.out.println(ans);
	}
	
}
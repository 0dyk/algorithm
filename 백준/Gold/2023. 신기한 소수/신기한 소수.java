import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static StringBuilder sb = new StringBuilder();
	static int N, max, min;	
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		
		solve(0,N);
		System.out.println(sb);
	}
	
	public static void solve(int num, int cnt) {
	    if (cnt == 0) {
	        if (isPrime(num)) sb.append(num).append("\n");
	        return;
	    }
	    
	    for (int i = 1; i<10; i++) {
	        int next = num*10+i;
	        if (isPrime(next)) solve(next, cnt - 1);
	    }
	}
	
	public static boolean isPrime(int num) {
		if(num < 2) return false;
		for(int i = 2; i <= Math.sqrt(num); i++) {
			if(num%i == 0) return false;
		}
		return true;
	}
}
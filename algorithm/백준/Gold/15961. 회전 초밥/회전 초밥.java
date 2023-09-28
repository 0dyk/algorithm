import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	static int N, D, K, C;
	static int[] arr;
	static int[] eat;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] str = br.readLine().split(" ");
		N = Integer.parseInt(str[0]);
		D = Integer.parseInt(str[1]);
		K = Integer.parseInt(str[2]);
		C = Integer.parseInt(str[3]);
		
		arr = new int[N];
		eat = new int[3001];
		
		for(int i = 0; i < N; i++) {
			String s = br.readLine();
			arr[i] = Integer.parseInt(s);
		}
		
		int gazi = 0;
		eat = new int[3001];
		for(int i = 0; i < K; i++) {
			// 처음 먹는 경우
			if(eat[arr[i]] == 0) {
				gazi++;
			}
			eat[arr[i]]++;	
		}
		
		int maxGazi = gazi;
		// 0번 시작인데 N-1번 시작까지 해보자
		for(int i = 0; i < N - 1; i++) {
			// i는 뺄 음식의 인덱스 -> N-2번까지 뺴보자
			// i번을 빼면 음식을 안 먹은 경우
			if(--eat[arr[i]] == 0) {
				gazi--;
			}
			// 다음 음식의 idx
			int idx = (i + K) % N;
			
			// 이 음식을 처음 먹은 경우
			if(++eat[arr[idx]] == 1) {
				gazi++;
			}
			
			if(eat[C] == 0) {
				if(gazi + 1> maxGazi) maxGazi = gazi + 1;
			}else {
				if(gazi> maxGazi) maxGazi = gazi;
			}

		}
		
		System.out.println(maxGazi);
	}
	
}
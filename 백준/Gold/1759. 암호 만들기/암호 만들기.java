import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	static StringBuilder sb = new StringBuilder();
	static int L, C;
	static char[] arr;
	static char[] res;
	static boolean[] visited;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] str = br.readLine().split(" ");
		L = Integer.parseInt(str[0]);
		C = Integer.parseInt(str[1]);
		arr = new char[C];
		res = new char[L];
		visited = new boolean[C];
		
		str = br.readLine().split(" ");

		for(int i = 0; i < C; i++) {
			arr[i] = str[i].charAt(0);
		}
		
		Arrays.sort(arr);
		
		permutation(0, 0, 0, 0);
		
		System.out.println(sb);
	}
	
	// 시작 인덱스, 현재 뽑은 개수, 뽑아야 하는 개수=L, 뽑은 모음의 개수, 뽑은 자음의 개수
	private static void permutation(int idx, int cnt, int moum, int jaum) {
		if(cnt == L) {
			if(moum >= 1 && jaum >= 2) {
				for(int i = 0; i < L; i++) {
					sb.append(res[i]);
				}
				sb.append("\n");	
			}
			return;
		}
		
		for(int i = idx; i < C; i++) {
			res[cnt] = arr[i];
			
			if(cnt >= 1 && (int)res[cnt - 1] > (int)res[cnt]) {
				continue;
			}
			
			if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
				permutation(i + 1, cnt + 1, moum + 1, jaum);				
			}else {
				permutation(i + 1, cnt + 1, moum, jaum + 1);
			}
		}
	}
	
	
}
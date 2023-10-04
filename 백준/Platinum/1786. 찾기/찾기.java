import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

		char[] T = in.readLine().toCharArray();
		char[] P = in.readLine().toCharArray();
		
		int M = P.length;
		int N = T.length;
		
		int[] pi = new int[M];
		
		// 부분 일치 테이블 생성
		for(int i=1, j=0; i<M; i++) {
			while(j>0 && P[i]!=P[j]) {
				j = pi[j-1];
			}
			
			if(P[i] == P[j]) {
				pi[i] = ++j;
			}else {
				pi[i] = 0;
			}
		}
		
		// P에서 T 찾기
		int cnt = 0;
		List<Integer> list = new ArrayList<Integer>();
		
		for(int i=0, j=0; i<N; i++) {
			while(j>0 && T[i] != P[j]) {
				j = pi[j-1];
			}
			
			if(T[i] == P[j]) {
				if(j == M-1) {
					cnt++;
					list.add(i-j+1);
					
					j = pi[j];
				}else {
					j++;
				}
			}
		}
		
		out.write(cnt+"\n");
		for(int n : list) {
			out.write(n+" ");
		}
		
		out.close();
	}
}
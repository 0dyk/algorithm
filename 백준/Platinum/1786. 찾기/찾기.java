import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

	static char[] T;
	static char[] P;
	static int tLength;
	static int PLength;
	static List<Integer> list;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		list = new ArrayList<>();
		
		T = br.readLine().toCharArray();
		P = br.readLine().toCharArray();
		
		tLength = T.length;
		PLength = P.length;
		
		// 1단계 : 부분일치 테이블 작성
		int[] pi = new int[PLength];
		
		// i : 접미사 인덱스
		// j : 접두사 인덱스
		
		for(int i = 1, j = 0; i < PLength; i++) {
			while(j > 0 && P[i] != P[j]) {
				j = pi[j-1];
			}
			
			// 접미사와 접두사가 같은 경우, 그 길이를 부분일치 테이블에 기록
			if(P[i] == P[j]) {
				pi[i] = ++j;
			}
			else {
				pi[i] = 0;
			}
		}
		
		// 2단계 : 부분일치 테이블을 활용하여 본문과 패턴 비교하기
		int cnt = 0;
		
		// i : 본문 인덱스
		// j : 패턴 인덱스
		for(int i = 0, j = 0; i < tLength; i++) {
			
			// 본문과 패턴이 불일치하면
			while(j > 0 && T[i] != P[j]) {
				j = pi[j-1];
			}
			
			// 본문과 패턴의 한 글자가 일치하면
			if(T[i] == P[j]) {
				
				// j가 패턴의 마지막 인덱스라면 패턴과 일치하는 단어찾기 완료
				if(j == PLength-1) {
					cnt++;
					
					list.add(i - j + 1);
					
					// j 위치까지는 일치 했으므로 일치했던 곳의 인덱스 번호를 부분일치 테이블에서 가져옴
					j = pi[j];
				}else {
					j++;
				}
			}
		}
		
		System.out.println(cnt);
		for(Integer i : list) {
			System.out.print(i + " ");
		}
		
	}
}
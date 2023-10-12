import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
	static StringBuilder sb = new StringBuilder();

	static int[] clr = new int[4];
	static int[] num = new int[13];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; tc++) {
			
			for(int i = 0; i < 4; i++) clr[i] = 0;
			for(int i = 0; i < 13; i++) num[i] = 0;
			
			String[] card = br.readLine().split(" ");
			
			for(int i = 0; i < 5; i++) {
				if(card[i].charAt(0) == 'S') ++clr[0];
				else if(card[i].charAt(0) == 'D') ++clr[1];
				else if(card[i].charAt(0) == 'H') ++clr[2];
				else if(card[i].charAt(0) == 'C') ++clr[3];
				
				int n = 0;
				
				if(card[i].charAt(1) == 'A') n = 0;
				else if(card[i].charAt(1) >= '2' && card[i].charAt(1) <= '9') n = card[i].charAt(1) - '1';
				else if(card[i].charAt(1) == 'T') n = 9;
				else if(card[i].charAt(1) == 'J') n = 10;
				else if(card[i].charAt(1) == 'Q') n = 11;
				else if(card[i].charAt(1) == 'K') n = 12;
				
				++num[n];
			}
			
			// 모두 동일한 컬러인가.
			boolean flush = false;
			for(int i = 0; i < 4; i++) if(clr[i] == 5) {flush = true; break;}
			
			// 모두 연속된 값인가.
			boolean straight = false;
			for(int i = 0; i < 13; i++) {
				if(num[i] == 1 && num[(i+1)%13] == 1 && num[(i+2)%13] == 1 
						&& num[(i+3)%13] == 1 && num[(i+4)%13] == 1) {
					straight = true;
					break;
				}
			}
			
			// 최대 동일 개수
			int cnt = 0;
			for(int i = 0; i < 13; i++) {
				if(num[i] > cnt) cnt = num[i];
			}
			
			// 2가 있는가
			int isTwo = 0;
			for(int i = 0; i < 13; i++) {
				if(num[i] == 2) ++isTwo;
			}
			
			
			if(flush && straight) {
				System.out.println("#" + tc + " Straight Flush");
			}else if(cnt == 4) {
				System.out.println("#" + tc + " Four of a Kind");
			}else if(cnt == 3 && isTwo == 1) {
				System.out.println("#" + tc + " Full House");
			}else if(flush) {
				System.out.println("#" + tc + " Flush");
			}else if(straight) {
				System.out.println("#" + tc + " Straight");
			}else if(cnt == 3) {
				System.out.println("#" + tc + " Three of a kind");
			}else if(isTwo == 2) {
				System.out.println("#" + tc + " Two pair");
			}else if(isTwo == 1) {
				System.out.println("#" + tc + " One pair");
			}else {
				System.out.println("#" + tc + " High card");
			}
			
			
		}
		
//		System.out.println(sb);
	}
}
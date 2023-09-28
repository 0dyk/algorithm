import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static StringBuilder sb = new StringBuilder();
	static int k, h, x, y;
	static String[] str;
	static int[][] arr;
			
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		// input
		k = Integer.parseInt(br.readLine());
		str = br.readLine().split(" ");
		h = Integer.parseInt(br.readLine());
		
		// 1칸짜리 종이에 찍은 위치 h
		x = 1; y = 1;
		arr = new int[1][1];
		arr[0][0] = h;
		
		// 접힌 상태에서 펼쳐나가기(str의 뒤에서부터 탐색)
		for(int i = str.length - 1; i >= 0; i--) {
			String c = str[i];
			
			// D or U or R or L
			switch (c) {
			case "D":
				D(x,y);
				break;
			case "U":
				U(x,y);				
				break;
			case "R":
				R(x,y);
				break;
			case "L":
				L(x,y);
				break;
			} // end switch
			
		} // end 펼치기 끝
		
		// StringBuilder에 배열 넣기
		for(int i = 0; i < x; i++) {		
			for(int j = 0; j < y; j++) {
				sb.append(arr[i][j]);
				if(j != y - 1) sb.append(" ");
				else sb.append("\n");
			}
		}
		
		// 결과값 출력
		System.out.println(sb);
	}
	
	/*
	 * D : 윗면이 아랫면을 덮도록
	 * U : 아랫면이 윗면을 덮도록
	 * R : 왼쪽이 오른쪽을 덮도록
	 * L : 오른쪽이 왼쪽을 덮도록
	 * 
	 * D, U : 0 -> 2, 2 -> 0, 1 -> 3, 3 -> 1
	 * R, L : 0 -> 1, 1 -> 0, 2 -> 3. 3 -> 2
	 */
	
	// 위로 펼치기
	public static void D(int i, int j) {
		// 임시 배열 만들기(row값 두배)
		int[][] brr = new int[i*2][j];
		
		for(int r = 0; r < i; r++) {
			for(int c = 0; c < j; c++) {
				brr[i + r][c] = arr[r][c];
			}
		}
		
		// 펼쳐진 면의 경우 row값이 반대이다.
		for(int r = 0; r < i; r++) {
			for(int c = 0; c < j; c++) {
				if(arr[i - 1 - r][c] == 0) brr[r][c] = 2;
				else if(arr[i - 1 - r][c] == 1) brr[r][c] = 3;
				else if(arr[i - 1 - r][c] == 2) brr[r][c] = 0;
				else if(arr[i - 1 - r][c] == 3) brr[r][c] = 1;
			}
		}
		
		// 원본 배열에 붙여넣기, 배열의 크기값 수정
		arr = brr;
		x = x * 2;
	}
	
	// 아래로 펼치기
	public static void U(int i, int j) {
		int[][] brr = new int[i*2][j];
		
		for(int r = 0; r < i; r++) {
			for(int c = 0; c < j; c++) {
				brr[r][c] = arr[r][c];
			}
		}
		
		for(int r = 0; r < i; r++) {
			for(int c = 0; c < j; c++) {
				if(arr[i - 1 - r][c] == 0) brr[i+r][c] = 2;
				else if(arr[i - 1 - r][c] == 1) brr[i+r][c] = 3;
				else if(arr[i - 1 - r][c] == 2) brr[i+r][c] = 0;
				else if(arr[i - 1 - r][c] == 3) brr[i+r][c] = 1;
			}
		}
		
		arr = brr;
		x = x * 2;
	}
	
	// 왼쪽으로 펼치기
	public static void R(int i, int j) {
		// 임시 배열 만들기(col값 두배)
		int[][] brr = new int[i][j * 2];
		
		for(int r = 0; r < i; r++) {
			for(int c = 0; c < j; c++) {
				brr[r][c + j] = arr[r][c];
			}
		}
		
		// 펼쳐진 면의 경우 col값이 반대이다.
		for(int r = 0; r < i; r++) {
			for(int c = 0; c < j; c++) {
				if(arr[r][j - 1 - c] == 0) brr[r][c] = 1;
				else if(arr[r][j - 1 - c] == 1) brr[r][c] = 0;
				else if(arr[r][j - 1 - c] == 2) brr[r][c] = 3;
				else if(arr[r][j - 1 - c] == 3) brr[r][c] = 2;
			}
		}
		
		// 원본 배열에 붙여넣기, 배열의 크기값 수정
		arr = brr;
		y = y * 2;
	}
	
	// 오른쪽으로 펼치기
	public static void L(int i, int j) {
		int[][] brr = new int[i][j * 2];
		
		for(int r = 0; r < i; r++) {
			for(int c = 0; c < j; c++) {
				brr[r][c] = arr[r][c];
			}
		}
		
		for(int r = 0; r < i; r++) {
			for(int c = 0; c < j; c++) {
				if(arr[r][j - 1 - c] == 0) brr[r][c + j] = 1;
				else if(arr[r][j - 1 - c] == 1) brr[r][c + j] = 0;
				else if(arr[r][j - 1 - c] == 2) brr[r][c + j] = 3;
				else if(arr[r][j - 1 - c] == 3) brr[r][c + j] = 2;
			}
		}
		
		arr = brr;
		y = y * 2;
	}
}
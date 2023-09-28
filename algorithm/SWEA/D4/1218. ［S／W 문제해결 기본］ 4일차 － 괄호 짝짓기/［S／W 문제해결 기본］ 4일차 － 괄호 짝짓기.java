import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Solution {
	private static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for (int test_case = 1; test_case <= 10; test_case++) {
			sb.append("#" + test_case + " ");
			int N = Integer.parseInt(br.readLine());
			String str = br.readLine();
			Stack<Character> stack = new Stack<>();
			boolean answer = true;
			for(int i = 0; i < N; i++) {
				if(!answer) break;
				if(str.charAt(i) == '{' || str.charAt(i) == '[' || str.charAt(i) == '(' ||str.charAt(i) == '<') {
					stack.push(str.charAt(i));					
				}
				else {
					char pop = stack.pop();
					switch (str.charAt(i)) {
					case ')':
						if(pop == '(') break;
						else answer = false;
						break;
					case '}':
						if(pop == '{') break;
						else answer = false;
						break;
					case ']':
						if(pop == '[') break;
						else answer = false;
						break;
					case '>':
						if(pop == '<') break;
						else answer = false;
						break;
					}
				}
			}
			
			if(!stack.empty()) answer = false;
			
			if(answer) sb.append(1);
			else sb.append(0);
			
			sb.append("\n");
		}

		System.out.println(sb);
	}
}
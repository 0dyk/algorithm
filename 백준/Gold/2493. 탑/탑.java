import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
	static StringBuilder sb = new StringBuilder();
	
	
	public static class HI {
		int height, index;
		public HI(int a, int b) {	// 생성자...
			this.height = a;
			this.index = b;
		}
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N+1];
        Stack<Integer> st = new Stack<>();
        
        String[] str = br.readLine().split(" ");
        for(int i = 0; i < N; i++) {
        	st.push(Integer.parseInt(str[i]));
        }
        
        Stack<HI> stack = new Stack<>();

        for(int i = N; i > 0; i--) {
        	int now = st.pop();
        	
        	while(!stack.empty()) {
        		if(stack.peek().height <= now) {
        			arr[stack.peek().index] = i;
        			stack.pop();
        		}else {
        			break;
        		}
        	}
        	
        	stack.push(new HI(now,i));       	
        }
		
        while(!stack.empty()) {
        	HI namuzi = stack.pop();
        	arr[namuzi.index] = 0;
        }
        
        for(int i = 1; i < N; i++) {
        	sb.append(arr[i]).append(" ");
        }
        sb.append(arr[N]).append("\n");
		System.out.println(sb);
	}
}
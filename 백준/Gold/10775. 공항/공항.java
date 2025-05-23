import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;

public class Main {

    static int[] input;
    static TreeSet<Integer> check;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int G = Integer.parseInt(br.readLine());
        int P = Integer.parseInt(br.readLine());

        input = new int[P];
        check = new TreeSet<Integer>();
        for(int i = 1; i <= G; i++) {
            check.add(i);
        }

        for(int i = 0; i < P; i++) {
            input[i] = Integer.parseInt(br.readLine());
        }

        int answer = 0;

        for(int i = 0; i < P; i++) {
            Integer k = check.floor(input[i]);

            if(k != null) {
                check.remove(k);
                answer ++;
            } else {
                break;
            }
        }

        System.out.println(answer);
    }
}
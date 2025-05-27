import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {

    static int[] InOrder, PostOrder;
    static List<Integer> PreOrder;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        InOrder = new int[N];
        PostOrder = new int[N];
        PreOrder = new ArrayList<>();

        // left root right
        String[] str = br.readLine().split(" ");
        InOrder = Arrays.stream(str).mapToInt(Integer::parseInt).toArray();

        // left right root
        str = br.readLine().split(" ");
        PostOrder = Arrays.stream(str).mapToInt(Integer::parseInt).toArray();

        // root left right ?
        divide(0, N - 1, 0, N - 1);

        for(int i = 0; i < N; i++) {
            sb.append(PreOrder.get(i));
            if(i != N - 1) sb.append(" ");
        }

        System.out.println(sb);
    }

    static void divide(int inLeft, int inRight, int postLeft, int postRight) {
        if(inLeft > inRight || postLeft > postRight) {
            return;
        }

        // root
        int root = PostOrder[postRight];
        PreOrder.add(root);

        int inOrderRootIdx = 0;
        for(int i = inLeft; i <= inRight; ++i) {
            if(InOrder[i] == root) {
                inOrderRootIdx = i;
                break;
            }
        }

        int leftSize = inOrderRootIdx - inLeft;

        // left
        divide(inLeft, inOrderRootIdx - 1, postLeft, postLeft + leftSize - 1);

        // rifgt
        divide(inOrderRootIdx + 1, inRight, postLeft + leftSize, postRight - 1);
    }
}
import java.util.*;

class Solution {
    
    static int[][] board;
    
    public int[] solution(int rows, int columns, int[][] queries) {
        List<Integer> ans = new ArrayList<>();
        
        board = new int[rows][columns];
        
        for(int i = 0, k = 1; i < rows; ++i) {
            for(int j = 0; j < columns; ++j) {
                board[i][j] = k++;
            }
        }
        
        for(int i = 0; i < queries.length; ++i) {
            ans.add(rotate(queries[i]));
        }
        
        int[] answer = ans.stream().mapToInt(Integer::intValue).toArray();
        
        return answer;
    }
    
    static int rotate(int[] querie) {
        int k = board[querie[0] - 1][querie[1] - 1];
        
        int min_value = k;
        
        for(int i = querie[0] - 1; i < querie[2] - 1; ++i) {
            board[i][querie[1] - 1] = board[i + 1][querie[1] - 1];
            if(min_value > board[i][querie[1] - 1]) min_value = board[i][querie[1] - 1];
        }
        for(int i = querie[1] - 1; i < querie[3] - 1; ++i) {
            board[querie[2] - 1][i] = board[querie[2] - 1][i + 1];
            if(min_value > board[querie[2] - 1][i]) min_value = board[querie[2] - 1][i];
        }
        for(int i = querie[2] - 1; i > querie[0] - 1; --i) {
            board[i][querie[3] - 1] = board[i - 1][querie[3] - 1];
            if(min_value > board[i][querie[3] - 1]) min_value = board[i][querie[3] - 1];
        }
        for(int i = querie[3] - 1; i > querie[1] - 1; --i) {
            board[querie[0] - 1][i] = board[querie[0] - 1][i - 1];
            if(min_value > board[querie[0] - 1][i]) min_value = board[querie[0] - 1][i];
        }
        
        board[querie[0] - 1][querie[1]] = k;
        
        return min_value;
    }
}
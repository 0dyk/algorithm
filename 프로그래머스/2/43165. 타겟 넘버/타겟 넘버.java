class Solution {
    
    int count;
    
    public int solution(int[] numbers, int target) {
        int answer = 0;
        
        count = 0;
        dfs(numbers, 0, 0, target);
        
        answer = count;
            
        return answer;
    }
    
    void dfs(int[] numbers, int idx, int value, int target) {
        if(numbers.length == idx) {
            if(value == target) {
                count++;
            }
            return;
        }
        
        dfs(numbers, idx + 1, value + numbers[idx], target);
        dfs(numbers, idx + 1, value - numbers[idx], target);
    }
}
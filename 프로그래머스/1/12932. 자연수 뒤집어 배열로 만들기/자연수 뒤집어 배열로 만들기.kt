class Solution {
    fun solution(n: Long): IntArray {
        var answer = mutableListOf<Int>()
        
        var tmp = n
        
        while(tmp > 0) {
            answer.add((tmp % 10).toInt())
            tmp /= 10
        }
        
        return answer.toIntArray()
    }
}
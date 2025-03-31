class Solution {
    public String solution(String[] survey, int[] choices) {
        String answer = "";
        
        int[] pick = new int[26];
        // 비동의 동의
        // ["AN", "CF", "MJ", "RT", "NA"]	[5, 3, 2, 7, 5]	"TCMA"
        for(int i = 0; i < choices.length; ++i) {
            pick[survey[i].charAt(0) - 'A'] -= (choices[i] - 4);
        }
        
        if(pick['R' - 'A'] >= pick['T' - 'A']) {
            answer += "R";
        }
        else {
            answer += "T";
        }
        
        if(pick['C' - 'A'] >= pick['F' - 'A']) {
            answer += "C";
        }
        else {
            answer += "F";
        }
        
        if(pick['J' - 'A'] >= pick['M' - 'A']) {
            answer += "J";
        }
        else {
            answer += "M";
        }
        
        if(pick['A' - 'A'] >= pick['N' - 'A']) {
            answer += "A";
        }
        else {
            answer += "N";
        }
        
        return answer;
    }
}
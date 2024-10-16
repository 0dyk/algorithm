#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string word) {
    int answer = 0;
    
    
    unordered_map<char, int> alp_to_idx = {
        {'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4}
    };

    int cnt[5] = { 781, 156, 31, 6, 1 };
    
    for(int i = 0; i < word.length(); ++i){
        answer += cnt[i] * alp_to_idx[word[i]] + 1;
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int> um;

int solution(string word) {
    int answer = 0;
        
    um['A'] = 0;
    um['E'] = 1;
    um['I'] = 2;
    um['O'] = 3;
    um['U'] = 4;
    
    int len = word.length();

    int arr[5] = { 781, 156, 31, 6, 1 };

    for(int i = 0; i < len; ++i){
        answer += arr[i] * um[word[i]] + 1;

        // cout << "추가 : " << arr[i] * um[word[i]] + 1 << '\n';
        // cout << "합계 : " << answer << '\n';
    }

    // 1 + 5 + 25 + 125 + 625 = 781
    // 1 + 5 + 25 + 125 = 156
    // 1 + 5 + 25 = 31
    // 1 + 5 = 6;
    
    return answer;
}
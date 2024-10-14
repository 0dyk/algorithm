#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int i = 1; i <= sqrt(yellow); ++i){
        // 만들어 지는 경우
        if(yellow % i == 0){
            int tmp = yellow / i;
            // tmp, i로 가로 세로가 만들어짐
            
            int round = tmp * 2 + i * 2 + 4;
            
            if(round == brown){
                answer.push_back(tmp + 2);
                answer.push_back(i + 2);
                break;
            }
        }
    }
    
    return answer;
}
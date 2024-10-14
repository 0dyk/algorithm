#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int answer;
int num[10];

void check_sosu(int value){
    if(value <= 1) return;
    
    for(int i = 2; i <= sqrt(value); ++i){
        if(value % i == 0){
            return;
        }
    }
    answer++;
}

void permu(int value, int depth){
    // 기저 조건
    check_sosu(value);
    
    // 유도 부문
    for(int i = 0; i < 10; ++i){
        // 첫 글자 0
        if(depth == 0 && i == 0) continue;
        // 사용 불가능
        if(num[i] == 0) continue;
        
        num[i]--;
        permu(value * 10 + i, depth + 1);
        num[i]++;
    }
}

int solution(string numbers) {
    answer = 0;
    
    for(int i = 0; i < numbers.size(); ++i){
        num[numbers[i] - '0']++;
    }
    
    permu(0, 0);
    
    return answer;
}
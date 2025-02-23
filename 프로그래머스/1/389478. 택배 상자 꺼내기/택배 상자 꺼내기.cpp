#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    
    bool isLeft = true;
    int line = 0;
    int numLine = 0;
    
    for(int i = 1; i <= n; ++i) {
        
        if(isLeft){
            if(++line > w) {
                --line;
                isLeft = false;
            }
        }
        else{
            if(--line < 1){
                ++line;
                isLeft = true;
            }
        }
        
        if(numLine == line){
            answer++;
        }
        
        if(i == num) {
            numLine = line;
            answer++;
        }
        
        // cout << "Line : " << line << ", value : " << i << " , A : "<<  answer << '\n';
    }
    
    return answer;
}
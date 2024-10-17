#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int tmp = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '(') tmp++;
        else tmp--;
        
        if(tmp < 0) {
            answer = false;
            break;
        }
    }
    
    if(tmp != 0) answer = false;

    return answer;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 0을 제거하고 남은 문자열과 제거된 0의 개수 리턴
pair<string, int> remove_zero(string str) {
    string res = "";
    int cnt = 0;
    
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == '0') cnt ++;
        else res += '1';
    }
    
    return {res, cnt};
}

// 이진수로 변환

string length_to_binary(string str){
    int num = str.size();
    
    string res = "";
    int k = 262144; // 2^18, 15만 보다 큰 2의 제곱수

    while(k > 0){
        if(num >= k){
            res += '1';
            num -= k;
        } 
        else{
            if(res != ""){
                res += '0';
            }
        }
        k /= 2;
    }
    
    return res;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int cnt = 0;
    int zero_cnt = 0;
    
    while(s != "1"){
        cnt++;
        pair<string, int> tmp = remove_zero(s);
        zero_cnt += tmp.second;
        s = length_to_binary(tmp.first);
    }
    
    answer.push_back(cnt);
    answer.push_back(zero_cnt);
    
    return answer;
}
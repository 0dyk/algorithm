#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> str_numbers;
    for(int i = 0; i < numbers.size(); ++i){
        str_numbers.push_back(to_string(numbers[i]));
    }
    
    sort(str_numbers.begin(), str_numbers.end(), [](const string &str1, const string &str2) {
        return str1 + str2 > str2 + str1;
    });
    
    if(str_numbers[0] == "0") return "0";
    
    for(int i = 0; i < str_numbers.size(); ++i){
        answer += str_numbers[i];
        // cout << str_numbers[i] << '\n';
    }
    
    return answer;
}
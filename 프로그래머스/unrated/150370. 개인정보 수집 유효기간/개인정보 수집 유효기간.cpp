#include<iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int tyear = 0, tmonth = 0, tday = 0;
    for(int j = 0; j < 4; j++){
        tyear *= 10;
        tyear += today[j] - '0';
    }
    for(int j = 5; j < 7; j++){
        tmonth *= 10;
        tmonth += today[j] - '0';
    }
    for(int j= 8; j < 10; j++){
        tday *= 10;
        tday += today[j] - '0';
    }
    
    int ttday = 0;
    ttday += tyear * 12 * 28 + tmonth * 28 + tday;
    
    
    
    for(int i = 0; i < privacies.size(); i++){
        int year = 0, month = 0, day = 0;
        for(int j = 0; j < 4; j++){
            year *= 10;
            year += privacies[i][j] - '0';
        }
        for(int j = 5; j < 7; j++){
            month *= 10;
            month += privacies[i][j] - '0';
        }
        for(int j= 8; j < 10; j++){
            day *= 10;
            day += privacies[i][j] - '0';
        }
        
        int tday =  year * 12 * 28 + month * 28 + day;
        
        char now = privacies[i][11];
        
        for(int j = 0; j < terms.size(); j++){
            if(terms[j][0] == now){
                int m = 0;
                for(int k = 2; k < terms[j].size(); k++){
                    m *= 10;
                    m += terms[j][k] - '0';
                }
                tday += m * 28;
                break;
            }
        }
        
        if(tday - 1 < ttday){
            answer.push_back(i+1);
        }
    }    
    
    return answer;
}
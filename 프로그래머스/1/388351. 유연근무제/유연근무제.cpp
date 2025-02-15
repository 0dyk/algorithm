#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check[1001] = { false };

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int i = 0; i < 7; ++i){
        
        if((startday + i) % 7 == 0 || (startday + i) % 7 == 6) {

            continue;
        }
        
        for(int j = 0; j < schedules.size(); ++j) {
            
            if(check[j]) continue;
            
            if(schedules[j] / 100 * 60 + schedules[j] % 100 + 10 < timelogs[j][i] / 100 * 60 + timelogs[j][i] % 100) {
                
                check[j] = true;
            }
        }
    }
    
    for(int i = 0; i < schedules.size(); ++i){
        
        if(!check[i]) answer++;
    }
    
    return answer;
}
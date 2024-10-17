#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> end_time;
    
    for(int i = 0; i < progresses.size(); ++i){
        int tmp = ceil((double)(100 - progresses[i]) / speeds[i]);
        end_time.push_back(tmp);
    }
    
    int cur_time = 0;
    for(int i = 0; i < end_time.size(); ++i){
        if(cur_time < end_time[i]){
            cur_time = end_time[i];
            
            int tmp = 1;
            
            for(int j = i + 1; j < end_time.size(); ++j){
                if(end_time[j] <= cur_time){
                    ++tmp;
                    i = j;
                }else{
                    break;
                }
            }
            
            answer.push_back(tmp);
        }
    }
    
    return answer;
}
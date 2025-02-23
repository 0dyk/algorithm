#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    int serverAdd[25] = { 0 };
    int serverCount = 0;
    
    for(int i = 0; i < players.size(); ++i) {
    
        if(i >= k){
            serverCount -= serverAdd[i - k];
        }
        
        int tmp = players[i] / m - serverCount;
        
        if(tmp > 0) {            
            serverCount += tmp;
            serverAdd[i] = tmp;
            
            answer += tmp;
        }
    }
    
    return answer;
}
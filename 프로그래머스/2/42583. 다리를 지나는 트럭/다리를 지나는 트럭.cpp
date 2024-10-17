#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    // 트럭 무게, 끝나는 시간
    queue<pair<int,int>> q;
    
    int cur_seconds = 0;
    int cur_length = 0;
    int cur_weight = 0;
    for(int i = 0; i < truck_weights.size(); ++i){
        // 내려
        while(!q.empty() && q.front().second <= cur_seconds){
            cur_length--;
            cur_weight -= q.front().first;
            q.pop();
        }
        
        // 탑승 불가능한 경우 시간 추가        
        while(cur_length >= bridge_length || cur_weight + truck_weights[i] > weight){
            cur_seconds++;
            while(!q.empty() && q.front().second <= cur_seconds){
                cur_length--;
                cur_weight -= q.front().first;
                q.pop();
            }
        }
        
        // 차량 탑승
        q.push({truck_weights[i], cur_seconds + bridge_length});
        cur_length++;
        cur_weight += truck_weights[i];
        cur_seconds++;

        answer = cur_seconds + bridge_length;
    }
    
    return answer;
}
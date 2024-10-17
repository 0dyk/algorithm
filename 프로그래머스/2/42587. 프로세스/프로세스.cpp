#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int,int>> q;
    
    for(int i = 0; i < priorities.size(); ++i){
        q.push({i, priorities[i]});
    }
    
    sort(priorities.begin(), priorities.end());
    
    int cnt = 0;
    while(!q.empty()){
        int idx = q.front().first;
        int pri = q.front().second;
        q.pop();
        
        // 작업 처리하는 경우
        if(priorities[priorities.size() - 1] == pri){
            cnt++;
            priorities.pop_back();

            
            if(idx == location){
                answer = cnt;
                break;
            }
        }
        else{
            q.push({idx, pri});
        }
    }
    
    return answer;
}
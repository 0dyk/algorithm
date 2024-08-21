#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> dist;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    
    dist.push_back(rocks[0]);
    for(int i = 0; i < rocks.size(); ++i){
        if(i != rocks.size() - 1) dist.push_back(rocks[i+1] - rocks[i]);
        else dist.push_back(distance - rocks[i]);
    }
    
    // 굳이 left 자세히 찾을 필요 없는 것 같은..
    int left = 0, right = distance;
    
    while(left < right){
        // 거리의 최솟값
        int mid = (left + right) / 2;
        
        int tmp = 0, cnt = 0;
        for(int i = 0; i < dist.size(); ++i){
            tmp += dist[i];
            
            if(tmp < mid){
                cnt++;
            }else{
                tmp = 0;
            }
        }
        
        // 불가능 : 현재 거리로 최대값을 하려면 바위를 더 제거해야함
        if(cnt > n){
            right = mid;
        }
        // 가능
        else {
            left = mid + 1;
        }
    }
    
    // 모든 바위 제거하는 경우
    if(left == distance) answer = distance;
    else answer = left - 1;
    
    return answer;
}
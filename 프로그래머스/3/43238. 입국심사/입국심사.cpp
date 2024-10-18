#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check_simul(vector<int>& times, int n, long long k){
    long long tmp = 0;
    
    for(int i = 0; i < times.size(); ++i){
        tmp += k / times[i];
    }
    
    return tmp >= n;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    // 이 시간에 다 검사할 수 있어?
    long long left = 0;
    long long right = n * 1000000000LL / times.size();
    
    while(left < right){
        long long mid = (left + right) / 2;
        
        // mid가 가능한가?
        bool successed = check_simul(times, n, mid);
        
        if(successed){
            right = mid;
        }
        else{            
            left = mid + 1;
        }
    }
    
    answer = left;
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

// 해당 레벨로 퍼즐을 푸는데 필요한 시간
long long puzzle_simulation(int level, vector<int> &diffs, vector<int> &times){
    long long res = 0;
    
    for(int i = 0; i < diffs.size(); ++i){
        if(level >= diffs[i]){
            res += times[i];
        }
        else{
            res += (diffs[i] - level) * (times[i] + times[i-1]) + times[i];
        }
    }
    
    return res;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int n = diffs.size();
    
    // n개의 퍼즐 / 퍼즐의 난이도 diffs
    // 현재 퍼즐 time_cur / 이전 퍼즐 time_prev
    // 내 숙련도 level
    
    // diff <= level이면 time_cur 시간 해결
    // diff > level이면 diff - level번 틀린다. -> (diff - level) * (time_cur + time_prev) + time_cur
    
    // limit 내에 퍼즐을 모두 해결하기 위한 level의 최솟값
    
    // 숙련도로 이분탐색(log10만) * 시뮬레이션 (n)
    
    // 숙련도 최댓값 = 100_000
    
    // 이분탐색
    long long left = 1, right = limit;
    long long mid = 0;
    long long tmp_time = 0;
    
    while(left <= right){
        // 이분탐색 값
        mid = (left + right) / 2;
        
        // 퍼즐 푸는데 걸리는 시간
        tmp_time = puzzle_simulation(mid, diffs, times);
        
        // ok
        if(tmp_time <= limit){
            right = mid - 1;
        }
        // no
        else {
            left = mid + 1;
        }
    }
    
    answer = left;
    
    return answer;
}
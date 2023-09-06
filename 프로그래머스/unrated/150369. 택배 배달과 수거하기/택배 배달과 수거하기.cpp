#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    // 총 이동거리
    long long* dist = &answer;
    
    // i번째 배달하고 추가로 배달할 수 있을 수 있기 때문에
    // 값 유지
    int del = 0;
    int pic = 0;
    
    // 마지막부터 이 전까지 체크
    for(int i = n-1; i >= 0; i--){

        // + i번째의 배달해야할 상자 수
        del += deliveries[i];
 
        // + i번째의 수거해야할 상자 수
        pic += pickups[i];
        
        // i번째 수거를 위해 몇 번 돌아야 하는지?
        int cnt = 0;
        while(true){
            // 0보다 작다
            // 배달해야할 상자X, 수거해야할 상자 X면 break
            if(del <= 0 && pic <= 0) break;
            
            // 한바쿠 돌면
            cnt++;
            
            // cap만큼 del과 pic 처리
            del -= cap;
            pic -= cap;
        }
        // del, pic가 음수인 경우 다음 집에서 사용
        
        // 총 거리에 합산
        *dist += (i+1) * 2 * cnt;
    }
    
    return answer;
}
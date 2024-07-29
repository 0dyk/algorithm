#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int checked[1000];
priority_queue<int, vector<int>, greater<int>> pq;

int solution(int coin, vector<int> cards) {
    // 초기 라운드 1
    int answer = 1;
    
    // 카드의 수
    int n = cards.size();
    
    // 초기 카드로 가능한 경우 체크
    for(int i = 0; i < n / 3; ++i){
        checked[cards[i]] = 1;
        
        if(checked[n + 1 - cards[i]] != 0){
            // 0의 비용으로 PASS
            pq.push(0);
        }
    }
    
    // 라운드 진행
    for(int i = n / 3; i < n; ++i){
        checked[cards[i]] = 2;
        
        if(checked[n + 1 - cards[i]] != 0){
            // checked 값에 따라서 1 or 2의 비용
            pq.push(checked[n + 1 - cards[i]]);
        }
        
        // 2장 뽑을 때 마다
        if(i % 2 != 0){
            // 라운드 진행 불가
            if(pq.empty() || coin < pq.top()){
                break;
            }
            // 다음 라운드 진행
            else{
                coin -= pq.top();
                pq.pop();
                
                answer++;
            }
        }
    }
    
//     while(!pq.empty() && pq.top() <= coin){
//         answer++;
//         coin -= pq.top();
//         pq.pop();
//     }
    
//     if(answer > n / 3 + 1) answer = n / 3 + 1;
    
    return answer;
}
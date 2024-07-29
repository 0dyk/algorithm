#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int checked[1000];
priority_queue<int, vector<int>, greater<int>> pq;

int solution(int coin, vector<int> cards) {
    int answer = 1;
    
    int n = cards.size();
    
    for(int i = 0; i < n / 3; ++i){
        checked[cards[i]] = 1;
        
        if(checked[n + 1 - cards[i]] != 0){
            pq.push(0);
            // cout << cards[i] << " 와 " << n + 1 - cards[i] << " 초기 조합 \n";
        }
    }
    
    for(int i = n / 3; i < n; ++i){
        checked[cards[i]] = 2;
        
        if(checked[n + 1 - cards[i]] != 0){
            pq.push(checked[n + 1 - cards[i]]);
            // cout << cards[i] << " 와 " << n + 1 - cards[i] << " 조합 " << checked[n + 1 - cards[i]] << "\n";
        }
        
        if(i % 2 != 0){
            cout << pq.size() << '\n';
            
            if(pq.empty() || coin < pq.top()){
                break;
            }
            else{
                // cout << "코인 : " << coin << " - " << pq.top() << '\n';
                coin -= pq.top();
                pq.pop();
                
                answer++;
            }
        }
    }
    
    while(!pq.empty() && pq.top() <= coin){
        answer++;
        coin -= pq.top();
        pq.pop();
    }
    
    
    
    if(answer > n / 3 + 1) answer = n / 3 + 1;
    
    return answer;
}
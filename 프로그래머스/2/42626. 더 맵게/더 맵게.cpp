#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct comp {
    bool operator() (const int &a, const int &b) const {
        return a > b;
    }
};

priority_queue<int, vector<int>, comp> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(int i = 0; i < scoville.size(); ++i){
        pq.push(scoville[i]);
    }
    
    while(!pq.empty()){
        if(pq.top() >= K) break;
        
        if(pq.top() < K && pq.size() == 1) {
            answer = -1;
            break;
        }
        
        answer++;
        int tmp = pq.top();
        pq.pop();
        
        tmp += pq.top() * 2;
        pq.pop();
        
        pq.push(tmp);
    }
    
    return answer;
}
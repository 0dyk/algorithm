#include <iostream>
#include <string>
#include <vector>

using namespace std;

int _n;
vector<vector<int>> *_q;
vector<int> *_ans;

bool visited[31];

int answer = 0;

void calc() {
    
    for(int i = 0; i < (*_q).size(); ++i) {
        
        int cnt = 0;
        
        for(int j = 0; j < 5; ++j) {
            
            if(visited[(*_q)[i][j]]) cnt++;
        }
        
        if((*_ans)[i] != cnt) return;
    }

    answer ++;
}

void combi(int idx, int cnt) {
    
    if(cnt == 5) {

        calc();
        return;
    }
    
    if(idx > _n) return;
    
    combi(idx + 1, cnt);
    visited[idx] = true;
    combi(idx + 1, cnt + 1);
    visited[idx] = false;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    
    _n = n;
    _q = &q;
    _ans = &ans;
    
    combi(1, 0);
    
    
    
    return answer;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long answer;
vector<pair<int,long long>> v;
int w[1001][4];

long long solution(vector<int> weights) {

    answer = 0;
    
    sort(weights.begin(), weights.end());
    
    for(int i = 0; i < weights.size(); ++i){
        v.push_back({weights[i] , 1});
        w[v.size() - 1][0] = weights[i];
        w[v.size() - 1][1] = weights[i] * 2;
        w[v.size() - 1][2] = weights[i] * 3;
        w[v.size() - 1][3] = weights[i] * 4;
        
        for(int j = i + 1; j < weights.size();){
            if(weights[i] == weights[j]){
                v[v.size() - 1].second++;
                ++i;
                ++j;
            }else{
                break;
            }
        }
    }
    
    for(int i = 0; i < v.size() - 1; ++i){
        for(int j = i + 1; j < v.size(); ++j){
            if(w[i][0] == w[j][0]) answer += v[i].second * v[j].second;
            else if(w[i][1] == w[j][0] || w[i][0] == w[j][1]) answer += v[i].second * v[j].second;
            else if(w[i][2] == w[j][1] || w[i][1] == w[j][2]) answer += v[i].second * v[j].second;
            else if(w[i][2] == w[j][3] || w[i][3] == w[j][2]) answer += v[i].second * v[j].second;
        }
    }
    
    for(int i = 0; i < v.size(); ++i){
        if(v[i].second > 1){
            answer += v[i].second * (v[i].second - 1) / 2;
        }
    }
    
    return answer;
}
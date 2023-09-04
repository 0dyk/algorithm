#include<iostream>
#include <string>
#include <vector>

using namespace std;

int en, un;
int maxPlus, maxCost;
int order[7];
int user[100][2];
vector<int> emoticon;

void solve(){
    int plus = 0, cost = 0;
    for(int i = 0; i < un; i++){
        int sell = user[i][0];
        
        int sum = 0;
        for(int j = 0; j < en; j++){
            if(sell <= order[j]){
                sum += emoticon[j] * (100 - order[j]) / 100;
            }
        }
        
        if(sum >= user[i][1]){
            plus++;
        }else{
            cost += sum;
        }
    }
    
    if(plus > maxPlus){
        maxPlus = plus;
        maxCost = cost;
    }else if(plus == maxPlus && cost > maxCost){
        maxCost = cost;
    }
    
}

void combi(int cnt){
    if(cnt == en){
        solve();
        return;
    }
    
    for(int i = 1; i <= 4; i++){
        order[cnt] = i * 10;
        combi(cnt+1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    en = emoticons.size();
    un = users.size();
    maxPlus = 0;
    maxCost = 0;
    
    for(int i = 0; i < un; i++){
        user[i][0] = users[i][0];
        user[i][1] = users[i][1];
    }
    
    for(int i = 0; i < en; i++){
        emoticon.push_back(emoticons[i]);
    }
    
    combi(0);
    
    answer.push_back(maxPlus);
    answer.push_back(maxCost);
    
    return answer;
}
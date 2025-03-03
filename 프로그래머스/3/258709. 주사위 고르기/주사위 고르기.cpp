#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

int N;
vector<vector<int>> dice;
vector<int> order;
vector<int> order2;

int arr[501];
int brr[501];

vector<int> answer;
int max_win;

void dfs(int num1, int num2, int cnt){
    if(cnt == N / 2){
        arr[num1]++;
        brr[num2]++;
        return;
    }
    
    for(int i = 0; i < 6; ++i){
        num1 += dice[order[cnt]][i];
        num2 += dice[order2[cnt]][i];
        
        dfs(num1, num2, cnt + 1);
        
        num1 -= dice[order[cnt]][i];
        num2 -= dice[order2[cnt]][i];
    }
}

void check(){
    for(int i = 0; i < 501; ++i){
        arr[i] = brr[i] = 0;
    }
    
    order2.clear();
    for(int i = 0; i < N; ++i){
        if(find(order.begin(), order.end(), i) == order.end()){
            order2.push_back(i);
        }
    }

    dfs(0, 0, 0);
    
    for(int i = 1; i < 501; ++i){
        brr[i] += brr[i-1];
    }
    
    int tmp = 0;
    for(int i = 1; i < 501; ++i){
        if(arr[i] > 0 && brr[i-1] > 0){
            tmp += arr[i] * brr[i-1];
        }
    }
    
    if(tmp > max_win){
        answer.clear();
        max_win = tmp;
        for(int i = 0; i < order.size(); ++i){
            answer.push_back(order[i] + 1);
        }
    }
}

void combi(int start, int cnt){
    if(cnt == N / 2){
        check();
        return;
    }
    
    for(int i = start; i < N; ++i){
        order.push_back(i);
        combi(i + 1, cnt + 1);
        order.pop_back();
    }
}

vector<int> solution(vector<vector<int>> _dice) {
    
    dice = _dice;
    N = dice.size();
    
    combi(0, 0);
    
    return answer;
}
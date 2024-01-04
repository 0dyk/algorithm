#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b){
    if(a[1] < b[1]) return true;
    else if(a[1] == b[1] && a[0] <= b[0]) return true;
    else return false;
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    // 가장 빨리 끝나는 순서대로 정렬 후 마지막 타임에 다 처리하면?
    
    // 정렬 -> target[1] 순으로
    
    sort(targets.begin(), targets.end(), comp);
    
    double missile = 0;
    
    for(int i = 0; i < targets.size(); ++i){
        // cout << "현재 target : " << targets[i][0] << " " << targets[i][1] << '\n';
        // cout << "현재 미사일 값 : " << missile << '\n';
        
        if(targets[i][0] < missile){
            continue;
        }else{
            missile = targets[i][1] - 0.5;
            answer++;
        }
        
        // cout << "미사일 값 변경 : " << missile << '\n';
    }
    
    return answer;
}
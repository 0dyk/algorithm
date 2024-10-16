#include <string>
#include <vector>

using namespace std;

int answer;
int target_num;

void DFS(vector<int>& numbers, int num, int idx){
    if(idx == numbers.size()){
        if(num == target_num) answer++;
        return;
    }
    
    DFS(numbers, num + numbers[idx], idx + 1);
    DFS(numbers, num - numbers[idx], idx + 1);
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    target_num = target;
    
    DFS(numbers, 0, 0);
    
    return answer;
}
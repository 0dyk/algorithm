#include <string>
#include <vector>
#define MAX_INT 2100000000
#define min(a, b) a < b ? a : b

using namespace std;

int n;
int num;
int answer;

int calc(int k){
    int value = 0;
    for(int i = 0; i < k; ++i){
        value = value * 10 + n;
    }
    return value;
}

void dfs(int cnt, int sum){
    if(sum == num){
        answer = min(answer, cnt);
        return;
    }
    if(cnt == 8){
        return;
    }
    
    for(int i = 1; i <= 8 - cnt; ++i){
        int tmp = calc(i);
        
        dfs(cnt + i, sum + tmp);
        dfs(cnt + i, sum - tmp);
        dfs(cnt + i, sum * tmp);
        dfs(cnt + i, sum / tmp);
    }
}

int solution(int N, int number) {
    n = N;
    num = number;
    answer = MAX_INT;
    
    dfs(0, 0);
    if(answer == MAX_INT) answer = -1;
    
    return answer;
}
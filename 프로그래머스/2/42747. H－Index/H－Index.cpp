#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    answer = citations.size();
    
    for(int i = 0; i < citations.size(); ++i){
        if(citations[i] >= answer) {
            break;
        }
        else{
            answer--;
        }
    }
    
    return answer;
}
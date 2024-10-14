#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int person_one[5] = {1, 2, 3, 4, 5};
int person_two[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int person_three[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    // 맞춘 개수
    int count[3] = {0, 0, 0};
    
    for(int i = 0; i < answers.size(); ++i){
        if(answers[i] == person_one[i % 5]){
            count[0]++;
        }
        if(answers[i] == person_two[i % 8]){
            count[1]++;
        }
        if(answers[i] == person_three[i % 10]){
            count[2]++;
        }
    }
    
    int max_answer = 0;
    for(int i = 0; i < 3; ++i) max_answer = max(max_answer, count[i]);
    
    for(int i = 0; i < 3; ++i) if(max_answer == count[i]) answer.push_back(i + 1);
    
    return answer;
}
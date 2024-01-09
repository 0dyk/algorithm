#include <string>
#include <vector>
#include <queue>

using namespace std;

// int arr[5001];

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    // begin ~ end 값과 idx를 따로 가져가기...
    // 이렇게 안했다가 많이 틀림
    for(int i = begin, idx = 0; i <= end; ++i, ++idx){
        if(i == 1){
            // arr[idx] = 0;
            answer.push_back(0);
            continue;
        }
        
        // k값의 범위를 몰랐었어...
        int tmp = 1;
        
        for(int k = 2; k * k <= i; ++k){    
            if(i % k == 0){
                // 천만 미만이라면 넣고 바로 끝
                if(i / k <= 10000000){
                    answer.push_back(i/k);
                    break;                    
                }
                // 천만 이상이라면 나눈 값(K)를 저장하고
                // 그 중에서 가장 큰 값을 설치
                else{
                    tmp = k;
                }
            }
        }
        
        // 답을 찾지 못한 경우
        // 1 or tmp중 가장 큰 값
        if(answer.size() == idx) {
            answer.push_back(tmp);
        }
    }
    
    // for(int i = 0; i <= end - begin; ++i){
    //     answer.push_back(arr[i]);
    // }
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    // 설계
    // H는 높은 값, w는 낮은 값으로 설정하고
    // 각 값들에서 max 값을 구하면 가능하다?
    int height = 0; int width = 0;
    for(int i = 0; i < sizes.size(); ++i){
        int tmp_height = max(sizes[i][0], sizes[i][1]);
        int tmp_width = min(sizes[i][0], sizes[i][1]);
        
        height = max(height, tmp_height);
        width = max(width, tmp_width);
    }
    
    answer = height * width;
    
    return answer;
}
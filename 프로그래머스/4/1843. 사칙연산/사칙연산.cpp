#include <vector>
#include <string>
#include <iostream>

#define mymin(X,Y) ((X < Y) ? X : Y)
#define mymax(X,Y) ((X > Y) ? X : Y)

using namespace std;

int solution(vector<string> arr)
{
int answer = -1;

    int max_value = 0;
    int min_value = 0;
    
    int tmp = 0;
    
    for(int i = arr.size() - 1; i >= 0; --i){
        if(arr[i][0] >= '0' && arr[i][0] <= '9'){
            tmp += stoi(arr[i]);
        }
        else if(arr[i] == "+"){
            continue;
        }
        else if(arr[i] == "-"){
            int tmp_max_value = max_value;
            int tmp_min_value = min_value;
            
            min_value = mymin(-(tmp_max_value + tmp), tmp_min_value - tmp);
            max_value = mymax(-(tmp_min_value + tmp), tmp_max_value + tmp - (2 * stoi(arr[i + 1])));
            tmp = 0;
        }
    }
    
    answer = max_value + tmp;
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

unordered_set<string> us;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size(); ++i) {
        string tmp = "";
        
        for(int j = 0; j < phone_book[i].size(); ++j) {
            tmp += phone_book[i][j];
            
            if(us.find(tmp) != us.end()) {
                answer = false;
            }
        }
        
        us.insert(phone_book[i]);
    }
    
    return answer;
}
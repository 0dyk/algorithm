#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long startNumber[12];

string solution(long long n, vector<string> bans) {
    string answer = "";
    
    sort(bans.begin(), bans.end(), 
        [](const string& a, const string& b) {
            if (a.size() == b.size()) {
                return a < b;
            }
            return a.size() < b.size();
        }
    );

    long long tmp = 1;
    for(int i = 1; i < 12; ++i) {
        if(i == 1) startNumber[i] = 1;
        else {
            startNumber[i] = startNumber[i-1] + tmp;
        }
        tmp *= 26;
    }
    
    for(int i = 0; i < bans.size(); ++i) {
        
        long long originalIdx = startNumber[bans[i].size()];

        long long k = 1;
        for(int j = bans[i].size() - 1; j >= 0 ; --j) {
            originalIdx += (long long)(bans[i][j] - 'a') * k;
            
            k *= 26;
        }
                
        if(originalIdx <= n) {
            n++;
        }
    }
    
    // cout << "n : " << n;
    
    long long k = 1;
    for(int i = 11; i >= 1; --i) {
        if(n >= startNumber[i]) {
            answer = string(i, 'a');
            n -= startNumber[i];
            for(int j = 0; j < i - 1; ++j) k *= 26;
            break;
        }
    }

    // cout << ", 남은 값 : " << n << ", " << k << '\n';
    
    for(int i = 0; i < answer.size(); ++i) {
        if(n >= k) {
            int tmp = n / k;
            answer[i] = 'a' + tmp;
            
            // cout << i << " 자리 변경, " << k << ", " <<tmp << ", " << answer[i] << '\n';
            
            n -= tmp * k;
        }
        
        k /= 26;
    }
    
    return answer;
}
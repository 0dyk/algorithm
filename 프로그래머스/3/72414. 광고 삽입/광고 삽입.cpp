#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long adv[360010];

int time_to_seconds(string str) {
    int time = 0;
    
    time += ((str[0] - '0') * 10 + (str[1] - '0')) * 3600;
    time += ((str[3] - '0') * 10 + (str[4] - '0')) * 60;
    time += ((str[6] - '0') * 10 + (str[7] - '0'));
    
    return time;
}

string seocnds_to_time(int time){
    string h = to_string(time / 3600);
    if(h.length() == 1) h = "0" + h;
    time %= 3600;
    
    string m = to_string(time / 60);
    if(m.length() == 1) m = "0" + m;
    time %= 60;
    
    string s = to_string(time);
    if(s.length() == 1) s = "0" + s;
    
    return h + ':' + m + ':' + s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    int p_time = time_to_seconds(play_time);
    int a_time = time_to_seconds(adv_time);

    for (int i = 0; i < logs.size(); ++i) {
        int start = time_to_seconds(logs[i].substr(0, 8));
        int end = time_to_seconds(logs[i].substr(9, 8));

        adv[start]++;
        adv[end]--;
    }

    for (int i = 1; i <= p_time; ++i) {
        adv[i] += adv[i - 1];
    }
    for (int i = 1; i <= p_time; ++i) {
        adv[i] += adv[i - 1];
    }


    int start_time = -1;
    long long max_time = -1;

    for (int i = 0; i + a_time - 1 <= p_time; ++i) {
        long long sum = adv[i + a_time - 1] - (i ? adv[i - 1] : 0);
        if (sum > max_time) {
            start_time = i;
            max_time = sum;
        }
    }

    answer = seocnds_to_time(start_time);

    return answer;
}
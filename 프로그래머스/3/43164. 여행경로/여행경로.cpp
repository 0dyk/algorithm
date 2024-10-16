#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool flag;
vector<string> answer;

bool comp(vector<string>& a, vector<string>& b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

bool comp_2(vector<string>& a, string& b) {
    return a[0] < b;
};

void DFS(vector<vector<string>>& tickets, bool visited[], string cur, int cnt) {
    if (cnt == N) {
        flag = true;
        return;
    }

    int idx = lower_bound(tickets.begin(), tickets.end(), cur,
        [](const vector<string>& ticket, const string& departure) {
            return ticket[0] < departure;
        }) - tickets.begin();

    for (int i = idx; i < N; ++i) {
        if (cur != tickets[i][0]) break;

        if (visited[i]) continue;

        visited[i] = true;
        answer.push_back(tickets[i][1]);

        DFS(tickets, visited, tickets[i][1], cnt + 1);
        if (flag) return;

        visited[i] = false;
        answer.pop_back();
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    N = tickets.size();
    bool* visited = new bool[N];
    for (int i = 0; i < N; ++i) visited[i] = false;

    sort(tickets.begin(), tickets.end(), comp);

    answer.push_back("ICN");
    DFS(tickets, visited, "ICN", 0);

    return answer;
}
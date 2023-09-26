#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define INF 2100000000
using namespace std;

constexpr int dx[4] = { 1,0,0,-1 };
constexpr int dy[4] = { 0,-1,1,0 };
constexpr char dir[4] = { 'd','l','r','u' };

int N, M, X, Y, R, C, K;

string answer2;

int dist(int x, int y){
    int sum = 0;
    if(x > R) sum += x-R;
    else sum += R-x;
    
    if(y > C) sum += y-C;
    else sum += C-y;
    
    return sum;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    N = n; M = m; X = x - 1; Y = y - 1; R = r - 1; C = c - 1; K = k;

    
    if(dist(X,Y) > K || (K - dist(X, Y)) % 2 == 1){
        return "impossible";
    }
    
    while (!(X == R && Y == C && answer.size() == K)) {
        for (int i = 0; i < 4; i++) {
            int nx = X + dx[i];
            int ny = Y + dy[i];

            // 경계 체크
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            // 이동거리 초과시
            if (dist(nx, ny) + answer.length() > K) continue;
                
            answer += dir[i];
            X = nx; Y = ny;
            break;
        }
    }

    return answer;
}
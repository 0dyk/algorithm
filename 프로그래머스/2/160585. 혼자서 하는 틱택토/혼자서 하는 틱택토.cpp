#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    int answer = 1;
    
    // 1. O, X의 개수
    int oCnt = 0, xCnt = 0;
    
    for(int i = 0; i < board.size(); ++i){
        for(int j = 0; j < 3; ++j){
            if(board[i][j] == 'O') ++oCnt;
            else if(board[i][j] == 'X') ++xCnt;
        }
    }
    
    // O, X 3개 개수
    int cnt[2] = {0, 0};
    
    if(oCnt == xCnt){
        // 3개 몇개씩 있는지
        for(int i = 0; i < 3; ++i){
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
                if(board[i][0] == 'X'){
                    ++cnt[1];
                }else if(board[i][0] == 'O'){
                    ++cnt[0];
                }
            }
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
                if(board[0][i] == 'X'){
                    ++cnt[1];
                }else if(board[0][i] == 'O'){
                    ++cnt[0];
                }
            }
        }
        
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
            if(board[1][1] == 'X'){
                ++cnt[1];
            }else if(board[1][1] == 'O'){
                ++cnt[0];
            }
        }
        if(board[2][0] == board[1][1] && board[1][1] == board[0][2]){
            if(board[1][1] == 'X'){
                ++cnt[1];
            }else if(board[1][1] == 'O'){
                ++cnt[0];
            }
        }
        
        // 마지막으로 X가 놨는데 O 3개가 존재한다? 불가능
        if(cnt[0] != 0) answer = 0;
        
        // X 3개가 2개 이상이다? 불가능
        // else if(cnt[1] > 2) answer = 0;
        
        // cout << cnt[0] << " " << cnt[1] << '\n';
        // cout << "마지막으로 X가 놨어요" << '\n';
    }else if(oCnt == xCnt + 1){
        for(int i = 0; i < 3; ++i){
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
                if(board[i][0] == 'X'){
                    ++cnt[1];
                }else if(board[i][0] == 'O'){
                    ++cnt[0];
                }
            }
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
                if(board[0][i] == 'X'){
                    ++cnt[1];
                }else if(board[0][i] == 'O'){
                    ++cnt[0];
                }
            }
        }
        
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
            if(board[1][1] == 'X'){
                ++cnt[1];
            }else if(board[1][1] == 'O'){
                ++cnt[0];
            }
        }
        if(board[2][0] == board[1][1] && board[1][1] == board[0][2]){
            if(board[1][1] == 'X'){
                ++cnt[1];
            }else if(board[1][1] == 'O'){
                ++cnt[0];
            }
        }
        
        if(cnt[1] != 0) answer = 0;
        // else if(cnt[0] > 2) answer = 0;
        
        // cout << cnt[0] << " " << cnt[1] << '\n';
        // cout << "마지막으로 O가 놨어요" << '\n';
    }
    // 말이 안됑
    else{
        answer = 0;
    }
        
    return answer;
}
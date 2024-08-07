#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int string_to_time(string str){
    int result = 0;
    result += stoi(str.substr(0, 2)) * 60;
    result += stoi(str.substr(3, 2));
    return result;
}

vector<string> string_parser(string str, char sep){
    istringstream ss1(str);

    string tmp;
    vector<string> result;

    while(getline(ss1,tmp,sep)){
        result.push_back(tmp);
    }
    return result;
}

string conv[6][2] = { {"A#", "a"}, {"C#", "c"}, {"D#", "d"}, {"F#", "f"}, {"G#", "g"}, {"B#", "b"} };

string shap_convert(string str){
    for(int i = 0; i < 6; ++i){
        int start_pos = 0;
        while((start_pos = str.find(conv[i][0], start_pos)) != std::string::npos) {
            str.replace(start_pos, 2, conv[i][1]);
            start_pos++;
        }        
    }
    
    return str;
}

string solution(string m, vector<string> musicinfos) {
    // 정답
    string music_name = "(None)";
    int p_time = 0;
    
    m = shap_convert(m);
    
    for(int i = 0; i < musicinfos.size(); ++i){
        vector<string> music = string_parser(musicinfos[i], ',');
        
        int start_time = string_to_time(music[0]);
        int end_time = string_to_time(music[1]);  
        int play_time = end_time - start_time;

        // 재생시간 부족
        if(play_time < m.size()){
            continue;
        }
        
        music[3] = shap_convert(music[3]);
        // cout << "음악 ㅣ " << music[3] << '\n';
        
        // 일치하는지 확인.
        for(int j = 0; j < music[3].size(); ++j){
            // cout << j << "번쨰에서 시작\n";
            for(int k = 0; k < m.size(); ++k){
                // cout << m[k] << " 와 " << music[3][(j + k) % music[3].size()] << " 비교\n";
                if(j + k > play_time){
                    break;
                }
                
                if(m[k] != music[3][(j + k) % music[3].size()]){
                    break;
                }
                
                if(k == m.size() - 1){
                    if(music_name == "(None)"){
                        music_name = music[2];
                        p_time = play_time;
                    }
                    else if(music_name != "(None)" && p_time < play_time){
                        music_name = music[2];
                        p_time = play_time;
                    }
                    break;
                }
            }
        }
        
    }
    
    return music_name;
}
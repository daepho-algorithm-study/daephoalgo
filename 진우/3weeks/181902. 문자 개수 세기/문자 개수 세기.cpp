#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52, 0);
    
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";

    for (char c : my_string) {
        string s(1, c); // char → string 변환
        for (int i = 0; i < 26; i++) {
            if (s == string(1, upper[i])) {  // 대문자 비교
                answer[i]++;
            } else if (s == string(1, lower[i])) { // 소문자 비교
                answer[26 + i]++;
            }
        }
    }
    return answer;
}

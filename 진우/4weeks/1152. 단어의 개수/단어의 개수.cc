#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string sentence;
    getline(cin, sentence);  // 한 줄 전체 입력

    istringstream text(sentence);  // 문자열 스트림으로 변환
    string word;
    int count = 0;

    // 공백 단위로 단어 추출
    while (text >> word) {
        count++;
    }

    cout << count << endl;
    return 0;
}

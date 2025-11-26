#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    string S;
    cin >> S;

    int len = S.length();
    set<string> arr; // 서로 다른 부분 문자열 저장

    // i = 시작 위치
    for (int i = 0; i < len; i++) {
        string word = ""; // i부터 j까지 이어붙여 만들 부분 문자열

        // j = 현재 문자
        for (int j = i; j < len; j++) {
            word += S[j];    // 한 글자씩 이어서 부분 문자열 생성
            arr.insert(word); // set에 추가 (중복 자동 제거)
        }
    }

    cout << arr.size() << "\n";
    return 0;
}

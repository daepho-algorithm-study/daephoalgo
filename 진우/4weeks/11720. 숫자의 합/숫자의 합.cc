#include <iostream>
#include <string>   // 문자열 입력을 위해 필요
using namespace std;

int main() {
    int T;          // 자릿수 개수
    cin >> T;

    string s;       // 숫자들을 문자열로 입력
    cin >> s;

    int result = 0;
    for (int i = 0; i < T; i++) {
        result += s[i] - '0';  // 문자 → 정수 변환
    }

    cout << result;
    return 0;
}

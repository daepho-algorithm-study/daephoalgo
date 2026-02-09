#include <iostream>
#include <string>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;               // 수식 문자열 입력 (예: "55-50+40")

    int result = 0;         // 최종 계산 결과
    string num;             // 숫자를 임시로 저장할 문자열
    bool flag = false;      // '-'가 한 번이라도 나왔는지 여부

    // 수식 문자열을 왼쪽부터 한 글자씩 탐색
    for (int i = 0; i <= s.size(); i++) {

        // 연산자를 만나면 지금까지 모은 숫자를 처리
        if (s[i] == '+' || s[i] == '-' || i == s.size()) {

            // '-'가 이미 등장했다면 무조건 빼기
            if (flag) {
                result -= stoi(num);
                num = "";   // 다음 숫자를 위해 초기화
            }
            // '-' 이전이라면 더하기
            else {
                result += stoi(num);
                num = "";   // 다음 숫자를 위해 초기화
            }
        }
        // 숫자인 경우 문자열로 이어 붙임
        else {
            num += s[i];
        }

        // '-'를 만난 순간부터 이후 숫자는 모두 빼야 하므로 flag 활성화
        if (s[i] == '-') 
            flag = true;
    }

    // 계산 결과 출력
    cout << result << "\n";

    return 0;
}

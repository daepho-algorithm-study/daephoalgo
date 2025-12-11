#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;  // 테스트 케이스 개수 입력

    for (int i = 0; i < T; i++) {
        stack<int> s;   // 괄호 검사용 스택
        string x;
        cin >> x;       // 괄호 문자열 입력

        // 문자열의 각 문자를 순차적으로 탐색
        for (int j = 0; j < (int)x.length(); j++) {
            if (x[j] == '(') {
                // 여는 괄호 '('이면 스택에 추가 (push)
                s.push(x[j]);
            }
            else { // x[j] == ')'
                // 스택이 비어있지 않고 정상적으로 '('가 매칭되는 경우
                if (!s.empty() && s.top() == '(') {
                    s.pop();    // 짝이 맞으므로 pop
                }
                else {
                    // 짝이 맞지 않는 ')'가 나온 경우
                    s.push(x[j]);  // 불일치 표시를 위해 스택에 push
                    break;         // 뒤를 볼 필요 없이 실패 확정 → 반복 종료
                }
            }
        }

        // 스택이 비어있다면 모든 괄호가 정상적으로 매칭됨
        if (s.empty()) {
            cout << "YES" << "\n";
        }
        else { // 스택에 남아있으면 매칭 실패
            cout << "NO" << "\n";
        }
    }
    return 0;
}

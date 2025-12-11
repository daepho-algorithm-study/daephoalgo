#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;   // 명령의 개수 입력

    stack<int> s;   // 정수를 저장할 스택 선언

    for (int i = 0; i < N; i++) {
        int cmd;
        cin >> cmd; // 명령 입력

        // 1 X → 정수 X를 스택에 push
        if (cmd == 1) {
            int x;
            cin >> x;       // push할 값 입력
            s.push(x);      // 스택 맨 위에 삽입
        }

        // 2 → 스택의 맨 위 값을 제거하고 출력 (비어있으면 -1)
        else if (cmd == 2) {
            if (s.empty()) {        // 스택이 비었으면
                cout << -1 << "\n";
            } else {
                cout << s.top() << "\n"; // 맨 위 값 출력
                s.pop();                // 맨 위 값 제거
            }
        }

        // 3 → 스택에 들어있는 데이터 개수 출력
        else if (cmd == 3) {
            cout << s.size() << "\n";
        }

        // 4 → 스택이 비어있으면 1, 아니면 0 출력
        else if (cmd == 4) {
            if (s.empty()) {
                cout << 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }

        // 5 → 스택의 맨 위 값 출력 (비어있으면 -1)
        else if (cmd == 5) {
            if (s.empty()) {
                cout << -1 << "\n";
            } else {
                cout << s.top() << "\n";
            }
        }
    }

    return 0;
}

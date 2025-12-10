#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;   // 명령어 개수 입력

    queue<int> q;  // 정수를 저장할 큐 선언 (FIFO)

    string cmd;
    for (int i = 0; i < N; i++) {
        cin >> cmd;   // 명령 입력

        // 정수 X를 큐에 넣기
        if (cmd == "push") {
            int X;
            cin >> X;
            q.push(X);
        }
        // 큐의 front 요소 출력 후 제거
        else if (cmd == "pop") {
            if (!q.empty()) {
                cout << q.front() << "\n";
                q.pop();
            }
            else cout << -1 << "\n";  // 큐가 비었으면 -1 출력
        }
        // 큐의 현재 크기 출력
        else if (cmd == "size") {
            cout << q.size() << "\n";
        }
        // 큐가 비었으면 1, 아니면 0 출력
        else if (cmd == "empty") {
            if (q.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        // 큐의 front 요소 출력 (제거 X)
        else if (cmd == "front") {
            if (!q.empty()) cout << q.front() << "\n";
            else cout << -1 << "\n";
        }
        // 큐의 back 요소 출력 (제거 X)
        else if (cmd == "back") {
            if (!q.empty()) cout << q.back() << "\n";
            else cout << -1 << "\n";
        }
    }

    return 0;
}

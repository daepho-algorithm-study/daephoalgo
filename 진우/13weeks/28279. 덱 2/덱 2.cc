#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;   // 명령어 개수 입력

    deque<int> dq;  // 덱 선언

    int cmd;
    for (int i = 0; i < N; i++) {
        cin >> cmd;   // 명령 입력

        int x;
        if (cmd == 1) {
            cin >> x;
            dq.push_front(x);      // 1: x를 덱의 앞에 넣기
        }
        else if (cmd == 2) {
            cin >> x;
            dq.push_back(x);       // 2: x를 덱의 뒤에 넣기
        }
        else if (cmd == 3) {
            // 3: 덱의 앞 요소 출력 후 제거
            if (dq.empty()) cout << -1 << "\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if (cmd == 4) {
            // 4: 덱의 뒤 요소 출력 후 제거
            if (dq.empty()) cout << -1 << "\n";
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if (cmd == 5) {
            // 5: 덱의 크기 출력
            cout << dq.size() << "\n";
        }
        else if (cmd == 6) {
            // 6: 덱이 비었는지 여부 출력 (비었으면 1, 아니면 0)
            cout << dq.empty() << "\n";
        }
        else if (cmd == 7) {
            // 7: 덱의 앞 요소 출력 (제거 X)
            if (dq.empty()) cout << -1 << "\n";
            else cout << dq.front() << "\n";
        }
        else if (cmd == 8) {
            // 8: 덱의 뒤 요소 출력 (제거 X)
            if (dq.empty()) cout << -1 << "\n";
            else cout << dq.back() << "\n";
        }
    }
    
    return 0;
}

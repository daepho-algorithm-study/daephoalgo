#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;  // 입력 개수

    stack<int> s;  // 정수를 저장할 스택

    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;

        if (x != 0) {
            s.push(x);  // 0이 아니면 push
        }
        else {
            s.pop();    // 0이면 pop
        }
    }

    int sum = 0;

    // 스택에 남은 모든 값을 pop하면서 합산
    while (!s.empty()) {
        sum += s.top(); // top 값 더하기
        s.pop();        // top 제거
    }

    cout << sum << "\n";

    return 0;
}

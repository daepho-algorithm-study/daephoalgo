#include <iostream>
#include <queue>      // priority_queue 사용을 위한 헤더

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;                  // 연산의 개수
    cin >> N;               // N 입력

    // 기본 priority_queue는 '최대 힙(Max Heap)'
    // → 가장 큰 값이 항상 top()에 위치
    priority_queue<int> q;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;           // 정수 하나 입력

        if (x == 0) {       // 0이 입력되면
            if (q.empty()) {
                // 힙이 비어있으면 0 출력
                cout << 0 << "\n";
            }
            else {
                // 현재 힙에서 가장 큰 값 출력
                cout << q.top() << "\n";

                // 가장 큰 값 제거
                q.pop();
            }
        }
        else {
            // 0이 아니면 힙에 값 삽입
            // 삽입 시 자동으로 힙 구조 유지 (O(log N))
            q.push(x);
        }
    }

    return 0;   // 프로그램 정상 종료
}
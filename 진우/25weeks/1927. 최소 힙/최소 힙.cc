#include <iostream>
#include <queue>   // priority_queue 사용

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);  // C와 C++ 입출력 동기화 해제 → 속도 향상
    cin.tie(nullptr);                 // cin과 cout 연결 해제 → 속도 향상

    int N;            // 연산의 개수
    cin >> N;         // N 입력

    // 최소 힙(Min Heap) 선언
    // 기본 priority_queue는 최대 힙이므로
    // greater<int>를 사용해 작은 값이 우선되도록 설정
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;     // 정수 입력

        if (x == 0) {  // 0이 입력되면
            if (q.empty()) {
                // 힙이 비어있으면 0 출력
                cout << 0 << "\n";
            }
            else {
                // 최소 힙이므로 가장 작은 값이 top()
                cout << q.top() << "\n";

                // 가장 작은 값 제거
                q.pop();
            }
        }
        else {
            // 0이 아니면 힙에 값 삽입
            // 삽입 시 자동으로 힙 구조 유지 (O(log N))
            q.push(x);
        }
    }

    return 0;  // 프로그램 정상 종료
}
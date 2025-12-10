#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;   // 카드 개수 입력

    queue<int> q;   // 카드들을 저장할 큐

    // 1부터 N까지 순서대로 큐에 저장
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    // 카드가 1장 남을 때까지 반복
    while (q.size() != 1) {
        q.pop();              // 맨 위 카드를 버림
        q.push(q.front());    // 그 다음 카드를 맨 뒤로 옮김
        q.pop();              // 방금 뒤로 옮긴 카드를 큐에서 제거 (앞쪽 제거)
    }

    // 마지막에 남은 카드 출력
    cout << q.front() << "\n";

    return 0;
}

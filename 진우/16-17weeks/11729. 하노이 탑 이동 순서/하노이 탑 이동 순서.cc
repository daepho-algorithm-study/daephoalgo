#include <iostream>

using namespace std;

// ---------------------------
// 하노이 탑 재귀 함수
// n   : 이동할 원판 개수
// one : 출발 기둥
// two : 보조 기둥
// three : 목적지 기둥
// ---------------------------
void move(int n, int one, int two, int three) {
    // [기저 조건] 원판이 1개이면 바로 출발 → 목적지 이동
    if (n == 1) {
        cout << one << " " << three << "\n";  // 이동 출력
        return;
    }
    else {
        // n-1개의 원판을 보조 기둥으로 이동
        // 출발: one, 목적지: two, 보조: three
        move(n - 1, one, three, two);

        // 가장 큰 원판을 출발 → 목적지 이동
        cout << one << " " << three << "\n";

        // n-1개의 원판을 목적지로 이동
        // 출발: two, 목적지: three, 보조: one
        move(n - 1, two, one, three);
    }
}

int main() {
    ios::sync_with_stdio(false);  
    cin.tie(nullptr);             

    int N;
    cin >> N;                     // 원판 개수 입력

    // 하노이 탑 이동 총 횟수 출력: 2^N - 1
    cout << (1 << N) - 1 << "\n";  // << 연산자 사용: 1 << N = 2^N

    // N개의 원판을 1번 기둥에서 3번 기둥으로 이동
    // 2번 기둥은 보조 기둥
    move(N, 1, 2, 3);

    return 0;
}

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    deque<int> dq;          // 풍선 번호를 저장하는 덱
    vector<int> arr(N + 1); // 풍선 번호 → 이동값

    // 풍선 번호는 1 ~ N, 이동값 입력
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        dq.push_back(i);    // 풍선 번호를 덱의 뒤에 넣음
    }

    int cnt = 0;            // 이동을 카운트하는 변수

    // 풍선이 모두 없어질 때까지 반복
    while (!dq.empty()) {

        // 1) 현재 풍선 꺼내기 (폭발)
        int cur = dq.front();
        dq.pop_front();

        int move = arr[cur]; // 현재 풍선의 이동값
        cout << cur << " ";  // 터진 풍선 번호 출력

        // 2) 양수 이동일 경우 최초 1칸 이동이 자동 수행되므로 -1 처리
        if (move > 0) move--;

        cnt = 0;  // 회전을 시작할 때 카운트 초기화

        // 3) 실제 회전 수행
        //    - 덱이 비지 않았고
        //    - cnt가 목표 move 값에 도달할 때까지 반복
        while (!dq.empty() && cnt != move) {
            if (move > 0) {
                // 오른쪽 이동: 맨 앞을 맨 뒤로 보냄
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;      // 이동 카운트 증가
            }
            else {
                // 왼쪽 이동: 맨 뒤를 맨 앞으로 보냄
                dq.push_front(dq.back());
                dq.pop_back();
                cnt--;      // 이동 카운트 감소
            }
        }
    }

    return 0;
}

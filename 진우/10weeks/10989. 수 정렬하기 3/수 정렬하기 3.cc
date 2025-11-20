#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int cnt_arr[10001] = { 0 }; 
    // cnt_arr[i] : 숫자 i가 입력에서 몇 번 등장했는지 저장하는 배열
    // 예) 입력이 3, 3, 5 라면 cnt_arr[3] = 2, cnt_arr[5] = 1

    // 입력값 카운팅
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        cnt_arr[x]++; 
        // 숫자 x가 입력될 때마다 해당 위치의 카운트를 증가
    }

    // 카운트 배열 기반으로 정렬된 숫자 출력
    for (int i = 1; i <= 10000; i++) {

        // while (cnt_arr[i]--) 의 동작 원리:
        //   - 후위 감소 연산자 (post-decrement) 사용
        //   - 조건 검사 시 현재 cnt_arr[i] 값을 먼저 사용한 후, 반복문 한 번 돌 때마다 값이 1 감소
        //   - cnt_arr[i]가 0이 되면 조건이 false가 되어 반복 종료
        //
        // 예: cnt_arr[5] = 3 이라고 할 때 반복 흐름
        //   1회차: 조건 = 3 (참), 출력 후 cnt_arr[5] = 2
        //   2회차: 조건 = 2 (참), 출력 후 cnt_arr[5] = 1
        //   3회차: 조건 = 1 (참), 출력 후 cnt_arr[5] = 0
        //   4회차: 조건 = 0 (거짓) → 종료
        //
        // 즉 cnt_arr[i]에 저장된 횟수만큼 숫자 i를 출력하는 효과
        while (cnt_arr[i]--) {
            cout << i << "\n";
        }
    }

    return 0;
}

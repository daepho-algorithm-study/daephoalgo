#include <iostream>
#include <vector>
#include <algorithm>  // reverse() 사용을 위해 필요

using namespace std;

int arr[21];          // 카드 번호를 저장할 배열 (1번 ~ 20번 사용)

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);                 

    // 처음 카드 상태: 1 ~ 20
    for (int i = 1; i <= 20; i++) {
        arr[i] = i;                   // arr[1] = 1, arr[2] = 2 ... arr[20] = 20
    }

    // 카드 구간 뒤집기 연산 10번 수행
    for (int i = 1; i <= 10; i++) {
        int s, e;
        cin >> s >> e;                // 뒤집을 시작 위치 s, 끝 위치 e 입력

        // arr[s]부터 arr[e]까지 순서를 뒤집는다
        // reverse의 범위는 [start, end) 이므로
        // arr + e + 1 까지 써야 arr[e]까지 포함됨
        reverse(arr + s, arr + e + 1);
    }

    // 최종 카드 상태 출력
    for (int i = 1; i <= 20; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
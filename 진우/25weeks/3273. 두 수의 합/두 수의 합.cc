#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 0;   // 조건을 만족하는 쌍의 개수를 저장할 전역 변수

/*
    정렬된 배열 A에서
    두 수의 합이 a가 되는 쌍의 개수를 구하는 함수
*/
void two_pointer(vector<int>& A, int a) {

    int start = 0;                  // 배열의 시작 인덱스
    int end = A.size() - 1;         // 배열의 마지막 인덱스

    /*
        start와 end를 양쪽에서 좁혀오면서
        두 수의 합을 비교하는 방식 (투 포인터 기법)
    */
    while (start < end) {

        int sum = A[start] + A[end];   // 현재 두 수의 합

        // 두 수의 합이 목표값과 같은 경우
        if (sum == a) {
            cnt++;     // 쌍 개수 증가

            // 이미 사용한 두 값이므로
            // 다음 후보 탐색을 위해 양쪽 모두 이동
            start++;
            end--;
        }
        // 합이 목표값보다 작으면
        else if (sum <= a) {
            // 더 큰 값을 만들기 위해
            // 왼쪽 포인터 증가
            start++;
        }
        // 합이 목표값보다 크면
        else {
            // 더 작은 값을 만들기 위해
            // 오른쪽 포인터 감소
            end--;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);                

    int N;
    cin >> N;   // 배열 크기 입력

    vector<int> arr(N);

    // 배열 입력
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 투포인터 사용을 위해 반드시 정렬
    sort(arr.begin(), arr.end());

    int x;
    cin >> x;   // 목표 합 입력

    two_pointer(arr, x);  // 두 수의 합이 x인 쌍 찾기

    cout << cnt << "\n";  // 결과 출력

    return 0;
}
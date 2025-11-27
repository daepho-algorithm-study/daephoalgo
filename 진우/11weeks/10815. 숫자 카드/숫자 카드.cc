#include <iostream>
#include <vector>
#include <algorithm>  // sort 함수 사용
using namespace std;

// -----------------------------
// BinarySearch(vector<int> arr, int target)
// 처음에 이런식으로 작성했더니 시간초과가 발생
// 이유: 함수가 호출 될 때 마다 arr에 해당되는 vector 복사가 발생
// 그래서 gpt에게 해결 방법을 물었더니 const와 &참조 사용하라고 함
// const: 이 함수 안에서 arr 벡터를 절대로 수정하지 않겠다라는 약속
// => 함수 안에서 값을 바꿀 필요가 없다면 const 사용하는게 적절하다고 함
// &(참조): 복사하지 않고 원본을 참조
// -----------------------------
bool BinarySearch(const vector<int>& arr, int target) {
    int left = 0;                // 탐색 범위의 왼쪽 인덱스
    int right = arr.size() - 1;  // 탐색 범위의 오른쪽 인덱스

    // left가 right를 넘지 않는 동안 반복
    while (left <= right) {
        int mid = (left + right) / 2;  // 중간 인덱스 계산

        // 중간 값이 target과 같으면 찾은 것
        if (arr[mid] == target) {
            return true;
        }
        // target이 중간 값보다 크면 오른쪽 구간 탐색
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        // target이 중간 값보다 작으면 왼쪽 구간 탐색
        else {
            right = mid - 1;
        }
    }

    // 탐색 범위를 모두 확인했는데도 target이 없으면 false 반환
    return false;
}

int main() {
    int N;
    cin >> N;  // num 벡터의 크기 입력

    // N개의 숫자를 저장할 벡터
    vector<int> num(N);
    for (int i = 0; i < N; i++) {
        cin >> num[i];  // 숫자 입력
    }

    sort(num.begin(), num.end());  // 이분 탐색을 위해 반드시 정렬

    int M;
    cin >> M;  // 찾고 싶은 카드의 개수 입력

    // M개의 카드 값을 저장할 벡터
    vector<int> card(M);
    for (int i = 0; i < M; i++) {
        cin >> card[i];  // 카드 값 입력
    }

    // 각 카드에 대해 num 벡터 안에 존재하는지 확인
    for (int i = 0; i < M; i++) {
        if (BinarySearch(num, card[i])) {  // 존재하면
            cout << 1 << " ";              // 1 출력
        }
        else {                              // 존재하지 않으면
            cout << 0 << " ";              // 0 출력
        }
    }

    cout << "\n";  // 마지막에 줄 바꿈
    return 0;      // 프로그램 종료
}

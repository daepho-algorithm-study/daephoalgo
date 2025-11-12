#include <iostream>
#include <vector>
#include <algorithm>  // sort 사용을 위한 헤더

using namespace std;

int main() {
    int N, k;
    cin >> N >> k;  // N: 응시자 수, k: 커트라인 순위

    vector<int> arr(N);  // 크기가 N인 벡터 생성

    // 점수 입력
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 점수를 내림차순 정렬
    sort(arr.begin(), arr.end(), greater<int>());

    // k번째 점수 출력 (1-based index이므로 k-1)
    cout << arr[k - 1] << "\n";

    return 0;
}

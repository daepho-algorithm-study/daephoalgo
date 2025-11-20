#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N); // N개의 원소를 저장할 벡터 생성

    // 값 입력 (push_back이 아니라 인덱스 접근으로 입력)
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 오름차순 정렬
    sort(arr.begin(), arr.end());

    // 정렬된 결과 출력
    for (int i = 0; i < N; i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}

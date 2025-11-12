#include <iostream>
#include <vector>
#include <algorithm> // sort() 사용을 위해 포함
using namespace std;

int main() {
    int N;
    cin >> N; // 정렬할 수의 개수 입력

    vector<int> arr(N); // 크기가 N인 벡터 생성

    // N개의 수 입력
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

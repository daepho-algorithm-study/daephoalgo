#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);  // C와 C++ 표준 입출력 동기화를 끔 → 입출력 속도 향상
    cin.tie(nullptr);             // cin과 cout의 묶음 해제 → 입출력 성능 향상

    int N;
    cin >> N;  // 좌표의 개수 입력

    vector<pair<int,int>> arr(N);  // N개의 좌표를 저장할 벡터(pair) 생성

    // 좌표 입력
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = {y, x};  // (y, x) 순서로 저장 → pair 기본 정렬 시 y 기준, y가 같으면 x 기준
    }

    sort(arr.begin(), arr.end());  // pair 기본 정렬
    // 정렬 기준:
    // 1) first = y 오름차순
    // 2) first가 같으면 second = x 오름차순

    // 정렬된 좌표 출력 (원래 순서대로 x, y 출력)
    for (int i = 0; i < N; i++) {
        cout << arr[i].second << " " << arr[i].first << "\n";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;  
    // 정렬할 좌표의 개수 입력받기

    vector<pair<int, int>> arr;

    // N개의 좌표 입력받기
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y});  
        // pair<int, int> 형태로 저장
        // 예: 3 4 → (3, 4)
    }

    // 기본 sort 사용
    sort(arr.begin(), arr.end());
    // pair 정렬 규칙:
    // 1) 첫 번째 값(x) 오름차순
    // 2) 첫 번째 값이 같으면 두 번째(y) 오름차순

    // 정렬된 결과 출력
    for (int i = 0; i < N; i++) {
        cout << arr[i].first << " " << arr[i].second << "\n";
    }

    return 0;
}

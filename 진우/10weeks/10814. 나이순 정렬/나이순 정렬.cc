#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    // (나이, 이름)를 저장하는 배열
    vector<pair<int, string>> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    // stable_sort 사용 (가입 순서 유지)
    stable_sort(arr.begin(), arr.end(),
        [](const pair<int,string> &a, const pair<int,string> &b){
            return a.first < b.first;   // 나이 기준 오름차순
        }
    );

    // 출력
    for (int i = 0; i < N; i++) {
        cout << arr[i].first << " " << arr[i].second << "\n";
    }

    return 0;
}

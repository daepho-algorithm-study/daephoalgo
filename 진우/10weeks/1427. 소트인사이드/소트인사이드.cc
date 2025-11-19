#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string N;
    cin >> N;  
    // 숫자를 문자열 형태로 입력받음
    // 예: 입력 "314159" → N = "314159"

    vector<int> arr;

    // 문자열의 각 문자를 숫자로 변환하여 저장
    for (char c : N) {
        arr.push_back(c - '0');  
        // '0'을 빼서 문자 → 정수 변환
        // 예: '3' - '0' = 3
    }

    // 내림차순 정렬 (큰 숫자부터)
    sort(arr.begin(), arr.end(), greater<>());
    // greater<>() : 비교 함수, 큰 값이 앞에 오도록 정렬

    // 정렬된 숫자 출력
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i];
    }

    cout << "\n";  // 줄바꿈 출력

    return 0;
}

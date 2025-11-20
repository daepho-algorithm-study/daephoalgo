#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;  // 입력 수의 개수

    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];  
    // 원래 입력 배열 저장

    // 1. 중복 제거 + 정렬
    vector<int> sorted_arr = arr;                
    sort(sorted_arr.begin(), sorted_arr.end());  
    // 오름차순 정렬
    sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());  
    // 중복 제거: unique가 연속된 중복 제거 후 새로운 끝 iterator 반환
    // erase로 그 뒤의 불필요한 원소 제거

    // 2. 각 숫자 -> 압축 값 맵 생성
    map<int, int> compress;
    for (int i = 0; i < sorted_arr.size(); i++) {
        compress[sorted_arr[i]] = i;  
        // sorted_arr[i] 값을 key로, 해당 값의 인덱스(i)를 value로 저장
        // 즉, "값 → 압축된 값" 매핑 생성
    }

    // 3. 압축된 값 출력
    for (int i = 0; i < N; i++) {
        cout << compress[arr[i]] << " ";  
        // 원래 배열 arr[i]를 압축 값으로 변환하여 출력
    }
}

#include <iostream>   
#include <vector>     

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);                

    int N, K;
    cin >> N >> K;    // N: 전체 원소 개수, K: 연속 구간 길이

    // 길이가 N인 배열 선언
    vector<int> arr(N);

    // 배열 값 입력
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 첫 번째 구간 [0 ~ K-1] 합 계산
    int result = 0;
    for (int i = 0; i < K; i++) {
        result += arr[i];
    }

    int i = 1;                // 시작 인덱스
    int mx = -99999999;       // 최대값 저장 (충분히 작은 값으로 초기화)

    // 윈도우가 배열 범위를 벗어나지 않는 동안 반복
    while (i + K <= N) {

        // 현재 구간 합이 최대값보다 크면 갱신
        if (result > mx) {
            mx = result;
        }

        // 다음 구간 합 계산
        // 이전 구간 합 - 빠지는 값 + 새로 들어오는 값
        int nx = result - arr[i - 1] + arr[i + K - 1];
        result = nx;

        i++;   // 인덱스를 오른쪽으로 한 칸 이동
    }

    // 마지막 구간에 대한 최대값 비교
    if (result > mx) {
        mx = result;
    }

    // 연속된 K개의 합 중 최댓값 출력
    cout << mx << "\n";

    return 0;   // 프로그램 종료
}

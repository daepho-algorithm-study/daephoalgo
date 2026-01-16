#include <iostream>   
#include <vector>    

using namespace std;

int main() {
    ios::sync_with_stdio(false);  
    cin.tie(nullptr);             

    int T;
    cin >> T;  // 테스트 케이스 개수 입력

    int N;
    for (int i = 0; i < T; i++) { // 각 테스트 케이스 반복
        cin >> N;                // 구할 파도반 수열 항 번호 입력

        // 파도반 수열 값을 저장할 배열 (최대 100까지)
        long long arr[101];

        // 초기값 설정 (파도반 수열의 기본 조건)
        arr[0] = 0;  // 사용하지 않는 인덱스
        arr[1] = 1;  // P(1)
        arr[2] = 1;  // P(2)
        arr[3] = 1;  // P(3)

        // 점화식 적용
        // P(n) = P(n-2) + P(n-3)
        for (int i = 4; i <= N; i++) {
            arr[i] = arr[i - 2] + arr[i - 3];
        }

        // N번째 파도반 수열 값 출력
        cout << arr[N] << "\n";
    }

    return 0;
}

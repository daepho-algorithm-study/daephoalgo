#include <iostream>
#include <vector>

using namespace std;

// 원본 배열
int arr[1025][1025];

// 누적 합 배열
// dp[i][j] = (1,1)부터 (i,j)까지의 합
int dp[1025][1025];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);                 

    int N, M;
    cin >> N >> M;   // N: 배열 크기, M: 구간 합 쿼리 개수

    // 배열 입력 + 누적 합 계산
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];   // 원본 배열 값 입력

            // 2차원 누적 합 공식
            // 위쪽 + 왼쪽 - 중복 영역 + 현재 값
            dp[i][j] = dp[i - 1][j]       // (1,1) ~ (i-1,j)
                     + dp[i][j - 1]       // (1,1) ~ (i,j-1)
                     - dp[i - 1][j - 1]   // 중복 영역 제거
                     + arr[i][j];         // 현재 칸 추가
        }
    }

    // 구간 합 쿼리 처리
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // (x1,y1) ~ (x2,y2) 구간 합 계산
        int result =
            dp[x2][y2]                  // 전체 영역
          - dp[x1 - 1][y2]              // 위쪽 제거
          - dp[x2][y1 - 1]              // 왼쪽 제거
          + dp[x1 - 1][y1 - 1];          // 중복 복구

        cout << result << "\n";          // 결과 출력
    }

    return 0; // 프로그램 종료
}

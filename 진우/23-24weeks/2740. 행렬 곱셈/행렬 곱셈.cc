#include <iostream>

using namespace std;

// 행렬 A : N행 M열
int A[101][101];
// 행렬 B : M행 K열
int B[101][101];
// 결과 행렬 : N행 K열
int result[101][101];

int main() {
    ios_base::sync_with_stdio(false);  // 입출력 속도 최적화
    cin.tie(nullptr);

    int N, M, K;

    // 행렬 A의 크기 입력 (N x M)
    cin >> N >> M;

    // 행렬 A의 원소 입력
    for (int i = 0; i < N; i++) {          // A의 행
        for (int j = 0; j < M; j++) {      // A의 열
            cin >> A[i][j];
        }
    }

    // 행렬 B의 크기 입력 (M x K)
    // A의 열(M)과 B의 행(M)이 같아야 행렬 곱 가능
    cin >> M >> K;

    // 행렬 B의 원소 입력
    for (int i = 0; i < M; i++) {          // B의 행
        for (int j = 0; j < K; j++) {      // B의 열
            cin >> B[i][j];
        }
    }

    // 행렬 곱셈 수행
    // result[n][k] = A의 n번째 행과 B의 k번째 열의 내적
    for (int n = 0; n < N; n++) {          // 결과 행렬의 행 인덱스
        for (int k = 0; k < K; k++) {      // 결과 행렬의 열 인덱스
            for (int m = 0; m < M; m++) {  // 내적 계산용 인덱스
                // A[n][m]과 B[m][k]를 곱해 누적
                result[n][k] += A[n][m] * B[m][k];
            }
            // result의 한 원소 출력
            cout << result[n][k] << " ";
        }
        cout << "\n";  // 한 행 출력 후 줄바꿈
    }

    return 0;
}
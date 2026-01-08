#include <iostream>
#include <vector>

using namespace std;

int K;          // K번째로 배열에 저장되는 값
int cnt = 0;    // 배열 저장 횟수 카운트
int answer = -1; // K번째 저장값이 없으면 -1

// ---------------------------
// 병합 함수
// A[p..q]와 A[q+1..r]를 병합하여 A[p..r]을 오름차순으로 정렬
// ---------------------------
void merge(vector<int>& A, int p, int q, int r) {
    int i = p;          // 왼쪽 배열 시작 인덱스
    int j = q + 1;      // 오른쪽 배열 시작 인덱스
    int t = 0;          // 임시 배열 tmp의 인덱스

    vector<int> tmp(r - p + 1); // 임시 배열 생성 (크기: 병합할 구간 길이)

    // 두 부분 배열을 비교하며 작은 값부터 tmp에 저장
    while (i <= q && j <= r) {
        if (A[i] <= A[j]) {
            tmp[t++] = A[i++];
        }
        else {
            tmp[t++] = A[j++];
        }
    }

    // 왼쪽 배열에 남은 값이 있으면 tmp에 복사
    while (i <= q) {
        tmp[t++] = A[i++];
    }

    // 오른쪽 배열에 남은 값이 있으면 tmp에 복사
    while (j <= r) {
        tmp[t++] = A[j++];
    }

    i = p;  // 원래 배열 A의 시작 위치
    t = 0;  // tmp의 시작 인덱스

    // tmp 배열의 값을 다시 A[p..r]에 복사하면서 K번째 저장 확인
    while (i <= r) {
        cnt++;              // 저장할 때마다 카운트 증가
        if (cnt == K) {     // K번째 저장이면 answer에 기록
            answer = tmp[t];
        }
        A[i++] = tmp[t++];  // 실제 A 배열에 값 저장
    }
}

// ---------------------------
// 병합 정렬 함수
// A[p..r]을 오름차순 정렬
// ---------------------------
void merge_sort(vector<int>& A, int p, int r) {
    if (p < r) {                // 구간에 2개 이상 원소가 있어야 정렬 가능
        int q = (p + r) / 2;    // 중간 지점 계산
        merge_sort(A, p, q);    // 전반부 정렬
        merge_sort(A, q + 1, r);// 후반부 정렬
        merge(A, p, q, r);      // 병합
    }
}

// ---------------------------
// 메인 함수
// ---------------------------
int main() {
    int N;  
    cin >> N >> K;             // 배열 크기 N과 K번째 저장 위치 입력

    vector<int> A(N);          // 정렬할 배열
    for (int i = 0; i < N; i++)
        cin >> A[i];           // 배열 원소 입력

    merge_sort(A, 0, N - 1);   // 병합 정렬 수행

    cout << answer << "\n";    // K번째 저장 값 출력
    return 0;
}

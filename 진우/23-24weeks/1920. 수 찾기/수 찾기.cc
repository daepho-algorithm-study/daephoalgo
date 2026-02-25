#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * binary_search(x, a)
 * - 정렬된 벡터 a에서 값 x가 존재하는지 이진 탐색으로 확인
 * - 존재하면 1, 존재하지 않으면 0 반환
 */
int binary_search(int x, vector<int>& a) {

    int left = 0;                 // 탐색 범위의 시작 인덱스
    int right = a.size() - 1;     // 탐색 범위의 끝 인덱스

    // 탐색 범위가 유효한 동안 반복
    while (left <= right) {
        // 중간 인덱스 계산
        int mid = (left + right) / 2;

        // 중간 값이 찾는 값과 같으면 성공
        if (x == a[mid]) {
            return 1;
        }
        // 찾는 값이 중간 값보다 크면 오른쪽 절반 탐색
        else if (x > a[mid]) {
            left = mid + 1;
        }
        // 찾는 값이 중간 값보다 작으면 왼쪽 절반 탐색
        else {
            right = mid - 1;
        }
    }

    // 끝까지 못 찾았으면 존재하지 않음
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;

    // 수의 개수 입력
    cin >> N;

    vector<int> A(N);
    // 수열 입력
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 이진 탐색을 위해 반드시 정렬
    sort(A.begin(), A.end());

    // 탐색할 값의 개수 입력
    cin >> M;
    
    int x;
    // 각 값에 대해 이진 탐색 수행
    for (int i = 0; i < M; i++) {
        cin >> x;
        cout << binary_search(x, A) << "\n";
    }

    return 0;
}
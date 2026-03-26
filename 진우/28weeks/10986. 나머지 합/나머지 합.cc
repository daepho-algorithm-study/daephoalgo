#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M; // N: 수열의 길이, M: 나누는 수

    // 수열 입력
    vector<long long> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 나머지의 발생 횟수를 기록할 배열
    // remainder[r] : 누적합을 M으로 나눈 나머지가 r이었던 지점의 개수
    vector<long long> remainder(M, 0);

    long long cnt = 0;   // 조건을 만족하는 구간의 총 개수
    long long sum = 0;   // 현재 지점까지의 누적합

    for (int i = 0; i < N; i++) {
        // 현재까지의 누적합 갱신
        sum += arr[i];

        // 누적합을 M으로 나눈 나머지 계산
        int r = sum % M;

        // [케이스 1] 0번 인덱스부터 현재(i)까지의 합 자체가 M으로 나누어떨어지는 경우
        if (r == 0) {
            cnt++;
        }

        // [케이스 2] 이전 지점들 중 누적합의 나머지가 현재와 같은(r) 지점들을 정답에 추가
        // S[j] % M == S[i] % M 이면, 구간 [i+1, j]의 합은 M의 배수라는 원리 이용
        cnt += remainder[r];

        // 현재 지점의 나머지 횟수를 기록하여 다음 지점들이 참조할 수 있게 함
        remainder[r]++;
    }

    // 결과 출력
    cout << cnt << "\n";

    return 0;
}
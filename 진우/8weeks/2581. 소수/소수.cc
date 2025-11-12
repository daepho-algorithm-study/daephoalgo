#include <iostream>
#include <vector>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;  // 구간의 시작(M)과 끝(N)을 입력받음

    vector<int> arr; // 소수를 저장할 벡터

    int result = 0;  // 소수 합계를 저장할 변수

    // M~N 구간의 모든 수를 검사
    for (int i = M; i <= N; i++) {
        int cnt = 0;  // 약수 개수를 세기 위한 변수

        // 1부터 i까지 나누어떨어지는 수의 개수 계산
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                cnt += 1;  // 나누어떨어지면 카운트 증가
            }
        }

        // 약수가 정확히 2개이면 소수 (1과 자기 자신)
        if (cnt == 2) {
            arr.push_back(i);  // 소수 벡터에 추가
        }
    }

    // 소수의 합 계산
    for (int i = 0; i < (int)arr.size(); i++) {
        result += arr[i];
    }

    // 결과 출력
    if ((int)arr.size() > 0) { // 소수가 하나라도 있을 경우
        cout << result << "\n" << arr[0] << "\n"; // 합계와 최소 소수 출력
    }
    else { // 소수가 없는 경우
        cout << -1 << "\n";
    }

    return 0;
}

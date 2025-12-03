#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 0 ~ 1,000,000까지 소수 여부를 저장하는 배열 (true = 소수, false = 소수 아님)
    vector<bool> primenum(1000001, true);
    primenum[0] = primenum[1] = false;  // 0과 1은 소수가 아님

    // 에라토스테네스의 체로 소수를 미리 구함
    for (int i = 2; i * i < 1000001; i++) {       // i는 sqrt(1000000) 이하까지만 탐색
        if (primenum[i]) {                        // i가 소수라면
            for (int j = i * i; j < 1000001; j += i) {  // i의 배수들을 소수가 아니라고 표시
                primenum[j] = false;
            }
        }
    }

    int T;
    cin >> T;  // 테스트 케이스 개수 입력

    int n;
    for (int i = 0; i < T; i++) {
        cin >> n;  // 조사할 숫자 입력

        vector<int> arr;  // n보다 작은 소수들을 저장할 벡터
        for (int i = 2; i < n; i++) {
            if (primenum[i]) arr.push_back(i);  // 소수라면 push
        }

        int cnt = 0;                 // (소수 + 소수 = n) 되는 경우의 수
        int left = 0;                // 맨 앞 포인터
        int right = arr.size() - 1;  // 맨 뒤 포인터

        // 투 포인터(two pointer) 방식으로 합이 n이 되는 소수 쌍을 찾기
        while (left <= right) {
            int sum = arr[left] + arr[right];

            if (sum == n) {  // 소수 쌍을 찾은 경우
                cnt++;
                left++;      // 다음 조합을 위해 왼쪽 증가
                right--;     // 오른쪽 감소
            }
            else if (sum < n) {
                left++;      // 합이 부족하므로 left 값을 증가
            }
            else {
                right--;     // 합이 크므로 right 값을 감소
            }
        }

        cout << cnt << "\n";  // 결과 출력
    }

    return 0;
}

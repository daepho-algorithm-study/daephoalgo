#include <iostream>   
#include <vector>    

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;     // N: 동전 개수, K: 만들어야 할 금액

    vector<int> arr(N);
    // 각 동전의 가치를 입력받음
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int cnt = 0;       // 사용한 동전의 총 개수

    // 가장 가치가 큰 동전부터 사용하기 위해 뒤에서부터 순회
    for (int i = N - 1; i >= 0; i--) {
        // 현재 동전으로 사용할 수 있는 최대 개수만큼 더함
        cnt += K / arr[i];

        // 해당 동전을 사용하고 남은 금액 계산
        K = K % arr[i];
    }

    // 최종적으로 사용한 동전의 총 개수 출력
    cout << cnt << "\n";

    return 0;
}

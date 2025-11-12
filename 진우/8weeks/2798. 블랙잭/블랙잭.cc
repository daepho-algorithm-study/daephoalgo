#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int result = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                int sum = arr[i] + arr[j] + arr[k]; // 합을 매번 새로 계산
                if (sum <= M && sum > result) {     // M을 넘지 않는 최대합 갱신
                    result = sum;
                }
            }
        }
    }

    cout << result << "\n";
    return 0;
}

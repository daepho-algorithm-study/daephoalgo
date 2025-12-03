#include <iostream>
#include <vector>

using namespace std;

// 최대공약수 함수
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a;
        a = b;
        b = temp % a;
    }
    return a;
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 간격의 GCD 계산
    int g = arr[1] - arr[0];
    for (int i = 1; i < N - 1; i++) {
        g = gcd(g, arr[i + 1] - arr[i]);
    }

    // 전체 구간길이 계산
    int totalLen = arr[N - 1] - arr[0];

    // 전체 있어야 할 나무 수
    int totalTrees = (totalLen / g) + 1;

    // 새로 심어야 하는 나무 수 = 전체 - 기존
    cout << totalTrees - N << "\n";

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int cnt1 = 0;   // 재귀 방식에서 fib(1), fib(2)가 호출된 횟수
int cnt2 = 0;   // DP 방식에서 반복문이 실행된 횟수

// -------------------------------
// 재귀 방식 피보나치
// -------------------------------
int fib(int n) {

    // fib(1) 또는 fib(2)가 호출될 때 카운트
    if (n == 1 || n == 2) {
        cnt1++;
        return 1;
    }

    // 재귀 호출
    return fib(n - 1) + fib(n - 2);
}

// -------------------------------
// DP 방식 피보나치
// -------------------------------
int fibonacci(int n) {

    vector<int> arr(n + 1);

    // 초기값
    arr[1] = arr[2] = 1;

    // 반복문이 실행될 때마다 카운트
    for (int i = 3; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
        cnt2++;
    }

    return arr[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    fib(N);
    fibonacci(N);

    cout << cnt1 << " " << cnt2 << "\n";

    return 0;
}

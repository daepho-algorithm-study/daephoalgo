#include <iostream>
using namespace std;

// 최대공약수(GCD)를 구하는 함수 — 유클리드 호제법
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

// 분수 a/b를 기약분수 형태로 바꿔서 pair(분자, 분모)로 반환
pair<int, int> def(int a, int b) {
    int g = gcd(a, b);     // a와 b의 최대공약수
    return { a / g, b / g }; // 분자와 분모를 gcd로 나눠 기약분수로 만듦
}

int main() {
    int arr[2][2];

    // 2×2 행렬 입력
    // arr[0][0] = a, arr[0][1] = b
    // arr[1][0] = c, arr[1][1] = d  로 사용됨
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> arr[i][j];
        }
    }

    // 두 분수 (a/b + c/d) 의 합을 계산
    // 분자 = ad + bc
    int A = (arr[0][0] * arr[1][1] + arr[1][0] * arr[0][1]);

    // 분모 = bd
    int B = arr[0][1] * arr[1][1];

    // 기약분수 변환
    pair<int, int> result = def(A, B);

    // 결과 출력
    cout << result.first << " " << result.second << "\n";

    return 0;
}

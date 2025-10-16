#include <iostream>
using namespace std;

int main() {
    int N;  // 줄의 개수 (피라미드의 높이)
    cin >> N;

    // [1단계] 위쪽 삼각형 (1줄 ~ N줄)
    for (int i = 1; i <= N; i++) {
        // ① 공백 출력: 위로 갈수록 공백이 많고, 아래로 갈수록 줄어듦
        int spaceCount = N - i;
        for (int j = 0; j < spaceCount; j++) {
            cout << " ";
        }

        // ② 별 출력: i번째 줄에는 (2*i - 1)개의 별
        int starCount = 2 * i - 1;
        for (int j = 0; j < starCount; j++) {
            cout << "*";
        }

        // 줄바꿈
        cout << "\n";
    }

    // [2단계] 아래쪽 삼각형 (N-1줄 ~ 1줄)
    for (int i = N - 1; i >= 1; i--) {
        // ① 공백 출력: 위로 갈수록 줄어듦
        int spaceCount = N - i;
        for (int j = 0; j < spaceCount; j++) {
            cout << " ";
        }

        // ② 별 출력: i번째 줄에는 (2*i - 1)개의 별
        int starCount = 2 * i - 1;
        for (int j = 0; j < starCount; j++) {
            cout << "*";
        }

        // 줄바꿈
        cout << "\n";
    }

    return 0;
}

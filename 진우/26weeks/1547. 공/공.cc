#include <iostream>

using namespace std;

int main() {
    int m, a, b;
    cin >> m;  // 컵을 섞는 횟수

    int num = 1; // 현재 공이 있는 컵 번호

    for (int i = 0; i < m; i++) {
        cin >> a >> b;  // 바꿀 컵 번호

        // 공이 a에 있으면 b로 이동
        if (num == a) {
            num = b;
        }

        // 공이 b에 있으면 a로 이동
        else if (num == b) {
            num = a;
        }
    }

    cout << num; // 공이 들어있는 컵 번호 출력

    return 0;
}
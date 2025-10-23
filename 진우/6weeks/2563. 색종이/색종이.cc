#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int paper[100][100] = { 0 }; // 0이면 빈칸, 1이면 색종이 붙음
    int a, b;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        for (int x = a; x < a + 10; x++) {
            for (int y = b; y < b + 10; y++) {
                paper[x][y] = 1; // 색종이 붙이기
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            result += paper[i][j]; // 1이면 넓이에 포함
        }
    }

    cout << result << "\n";
    return 0;
}

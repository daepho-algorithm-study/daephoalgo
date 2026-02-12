#include <iostream>
using namespace std;

char arr[3][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];

    // 가로 / 세로 검사
    for (int i = 0; i < 3; i++) {
        // 가로
        if (arr[i][0] != '.' &&
            arr[i][0] == arr[i][1] &&
            arr[i][1] == arr[i][2]) {
            cout << "YES\n";
            return 0;
        }

        // 세로
        if (arr[0][i] != '.' &&
            arr[0][i] == arr[1][i] &&
            arr[1][i] == arr[2][i]) {
            cout << "YES\n";
            return 0;
        }
    }

    // 대각선 (왼쪽 위 → 오른쪽 아래)
    if (arr[0][0] != '.' &&
        arr[0][0] == arr[1][1] &&
        arr[1][1] == arr[2][2]) {
        cout << "YES\n";
        return 0;
    }

    // 대각선 (오른쪽 위 → 왼쪽 아래)
    if (arr[0][2] != '.' &&
        arr[0][2] == arr[1][1] &&
        arr[1][1] == arr[2][0]) {
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";
    return 0;
}

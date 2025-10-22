#include <iostream>
#include <string>
using namespace std;

int main() {
    string arr[5]; // 5줄 입력
    int max_len = 0;

    // 입력
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        if ((int)arr[i].size() > max_len) {
            max_len = arr[i].size();
        }
    }

    // 세로 읽기
    for (int j = 0; j < max_len; j++) {       // 열 기준
        for (int i = 0; i < 5; i++) {         // 행 기준
            if (j < (int)arr[i].size()) {     // 존재할 때만 출력
                cout << arr[i][j];
            }
        }
    }

    cout << endl;
    return 0;
}

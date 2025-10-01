#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T; // 테스트 케이스 개수 입력

    for (int tc = 0; tc < T; tc++) {
        string arr;
        cin >> arr; // 문자열 입력
        cout << arr[0] << arr[arr.size() - 1] << "\n";
    }

    return 0;
}

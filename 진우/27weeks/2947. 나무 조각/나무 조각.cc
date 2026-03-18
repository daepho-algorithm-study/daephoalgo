#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[5];

    // 입력
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    // 정렬 진행
    while (true) {
        for (int i = 0; i < 4; i++) {
            if (arr[i] > arr[i + 1]) {
                // swap
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;

                // 출력
                for (int j = 0; j < 5; j++) {
                    cout << arr[j] << " ";
                }
                cout << "\n";
            }
        }

        // 배열이 {1,2,3,4,5}인지 확인
        if (arr[0] == 1 && arr[1] == 2 && arr[2] == 3 && arr[3] == 4 && arr[4] == 5) {
            break;
        }
    }

    return 0;
}
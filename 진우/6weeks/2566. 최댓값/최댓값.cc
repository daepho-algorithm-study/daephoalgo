#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int arr[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
        }
    }

    int mx = -1;

    int first = 0;
    int second = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[i][j] > mx) {
                mx = arr[i][j];
                first = i;
                second = j;
            }
        }
    }

    cout << mx << "\n";
    cout << first + 1 << " " << second + 1 << "\n";

    return 0;
}

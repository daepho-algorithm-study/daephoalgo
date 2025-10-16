#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> arr(2 * N, vector<int>(M));

    for (int i = 0; i < 2 * N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int result = arr[i][j] + arr[i + N][j];
            cout << result << " ";
        }
        cout << "\n";
    }
    return 0;
}

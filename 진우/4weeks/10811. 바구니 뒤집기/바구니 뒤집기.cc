#include <iostream>
#include <vector>
#include <algorithm> // reverse
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> basket(N);
    for (int i = 0; i < N; i++) basket[i] = i + 1;

    for (int m = 0; m < M; m++) {
        int i, j;
        cin >> i >> j;
        // i~j 범위 뒤집기 (0 기반 인덱스 보정)
        reverse(basket.begin() + (i - 1), basket.begin() + j);
    }

    for (int k = 0; k < N; k++) {
        cout << basket[k];
        if (k != N - 1) cout << " ";
    }
    cout << "\n";
    return 0;
}

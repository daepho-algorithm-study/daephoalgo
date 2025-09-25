#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> box(N, 0); // N개 바구니, 초기값 0

    for (int m = 0; m < M; m++) {
        int i, j, k;
        cin >> i >> j >> k;      // i~j번 바구니에 k 공을 넣기
        for (int x = i - 1; x < j; x++) {
            box[x] = k;
        }
    }

    // 출력: 공백으로 구분
    for (int y = 0; y < N; y++) {
        cout << box[y];
        if (y != N - 1) cout << " ";
    }
    cout << endl;

    return 0;
}

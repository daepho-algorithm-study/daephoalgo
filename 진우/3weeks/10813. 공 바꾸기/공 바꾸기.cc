#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    // N: 바구니의 개수
    // M: 바구니의 위치를 서로 교환하는 횟수

    vector<int> box; // 바구니에 담긴 공 번호를 저장하는 벡터

    // 1번 바구니부터 N번 바구니까지
    // 처음에는 각 바구니에 자신의 번호와 동일한 공을 넣음
    for (int x = 1; x <= N; x++) {
        box.push_back(x);
    }

    // M번에 걸쳐 바구니를 교환하는 작업 수행
    for (int m = 0; m < M; m++) {
        int i, j;
        cin >> i >> j;
        // i번 바구니와 j번 바구니의 공을 서로 교환

        // 현재 i번 바구니와 j번 바구니의 공 번호를 임시로 저장
        int a = box[i - 1];   // C++은 0부터 인덱스 → i-1
        int b = box[j - 1];

        // 두 바구니의 공을 서로 교환
        box[i - 1] = b;
        box[j - 1] = a;
    }

    // 모든 교환 작업이 끝난 후
    // 각 바구니에 들어 있는 공의 번호를 공백으로 구분하여 출력
    for (int idx = 0; idx < N; idx++) {
        cout << box[idx];
        if (idx != N - 1) {   // 마지막 값 뒤에는 공백을 출력하지 않음
            cout << " ";
        }
    }

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> N_card(N);   // 상근이가 가진 카드들을 저장할 벡터
    map<int, int> arr;       // 카드 숫자 → 등장 횟수를 저장하는 map (정렬된 상태 유지)

    // N개의 숫자 카드 입력
    for (int i = 0; i < N; i++) {
        cin >> N_card[i];
        arr[N_card[i]]++;   // 해당 숫자의 개수를 1 증가
    }

    int M;
    cin >> M;

    vector<int> M_card(M);  // 찾고 싶은 숫자 카드들 저장

    // M개의 질의에 대해 상근이가 몇 개 갖고 있는지 출력
    for (int i = 0; i < M; i++) {
        cin >> M_card[i];
        cout << arr[M_card[i]] << " ";
    }

    cout << "\n";

    return 0;
}

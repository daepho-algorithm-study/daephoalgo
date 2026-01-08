#include <iostream>
#include <vector>
using namespace std;

int N, M;          // N: 사용할 숫자의 최대값, M: 뽑을 개수
vector<int> arr;   // 현재 선택된 숫자들을 저장하는 배열

// 조합 생성 함수 (N과 M - 2 유형)
// n     : 현재까지 선택한 숫자의 개수
// start : 다음에 선택할 수 있는 최소 숫자
void sequence(int n, int start) {

    // [기저 조건]
    // M개를 모두 선택했으면 결과 출력
    if (n == M) {
        for (int x : arr)
            cout << x << ' ';
        cout << '\n';
        return;
    }

    // start부터 N까지 차례대로 선택
    for (int i = start; i <= N; i++) {

        // 현재 숫자 i 선택
        arr.push_back(i);

        // 다음 단계로 이동
        // 다음 숫자는 반드시 i보다 큰 수만 사용 가능
        sequence(n + 1, i + 1);

        // 백트래킹:
        // 선택했던 i를 제거하고 다른 경우 탐색
        arr.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    // 길이 M의 조합 생성 시작
    sequence(0, 1);

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int N, M;                 // N: 사용할 숫자의 범위 (1 ~ N), M: 수열 길이
vector<int> arr;          // 현재 만들고 있는 수열
bool visited[9] = { false }; // 숫자 사용 여부 체크 (1~8 사용 가능)

// 백트래킹 함수
// n : 현재까지 선택한 숫자의 개수
void sequence(int n) {
    // [기저 조건]
    // 길이가 M인 수열을 완성했으면 출력
    if (n == M) {
        for (int i = 0; i < (int)arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    // 1부터 N까지 숫자를 하나씩 선택
    for (int i = 1; i <= N; i++) {

        // 이미 사용한 숫자라면 건너뜀
        if (visited[i]) {
            continue;
        }

        // 선택 단계
        arr.push_back(i);     // 현재 수열에 i 추가
        visited[i] = true;    // i 사용 표시

        // 다음 자리 채우러 재귀 호출
        sequence(n + 1);

        // 되돌리기(백트래킹)
        visited[i] = false;   // i 다시 사용 가능하게
        arr.pop_back();       // 마지막에 넣은 값 제거
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;    // 입력 받기

    // 길이 M의 순열 생성 시작
    sequence(0);

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);                 

    int A, B, C;
    cin >> A >> B >> C;               // 트럭 1, 2, 3대 요금 입력

    vector<pair<int, int>> time;      // 시간 배열: (시간, 들어오면 +1, 나가면 -1)

    // 트럭 3대 입력
    for (int i = 0; i < 3; i++) {
        int s, e;
        cin >> s >> e;                // 트럭 i의 주차 시작(s)과 끝(e) 시간 입력

        time.push_back({ s, 1 });     // 트럭이 들어오면 +1
        time.push_back({ e, -1 });    // 트럭이 나가면 -1
    }

    // 시간 기준으로 정렬 (작은 시간부터 처리)
    sort(time.begin(), time.end());

    int cnt = 0;                       // 현재 주차된 트럭 수
    int prev = time[0].first;          // 이전 시간 (계산 기준)
    int total = 0;                      // 총 요금

    for (int i = 0; i < time.size(); i++) {

        int now = time[i].first;       // 현재 시간

        int duration = now - prev;     // 이전 ~ 현재 시간까지 구간 길이

        // 구간 동안 주차된 트럭 수에 따른 요금 계산
        if (cnt == 1) {
            total += duration * (1 * A);
        }
        else if (cnt == 2) {
            total += duration * (2 * B);
        }
        else if (cnt == 3) {
            total += duration * (3 * C);
        }

        cnt += time[i].second;        // 트럭 들어오면 +1, 나가면 -1
        prev = now;                   // 기준 시간 업데이트
    }

    cout << total << "\n";             // 총 요금 출력

    return 0;
}
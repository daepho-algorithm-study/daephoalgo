#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;                          // 전체 사람 수 (N은 항상 짝수)
vector<vector<int>> team;       // 능력치 행렬 team[i][j]
bool visited[22];               // visited[i] == true → i번 사람은 start 팀
int mn = 1000000001;             // 최소 능력치 차이 저장

// x : 다음에 선택할 사람의 시작 인덱스
// n : 현재 start 팀에 선택된 사람 수
void fun(int x, int n) {

    // start 팀 인원이 정확히 N/2명이 되면 점수 계산
    if (n == N / 2) {
        int start = 0;
        int link = 0;

        // 모든 사람 쌍 (i, j)에 대해
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {

                // 둘 다 start 팀인 경우
                if (visited[i] == true && visited[j] == true) {
                    start += team[i][j];
                }

                // 둘 다 link 팀인 경우
                if (visited[i] == false && visited[j] == false) {
                    link += team[i][j];
                }
            }
        }

        // 두 팀 능력치 차이 계산
        int result = abs(start - link);

        // 최소값 갱신
        if (result < mn) {
            mn = result;
        }
        return; // 이 조합 탐색 종료
    }

    // 아직 start 팀 인원이 부족한 경우
    // x부터 N-1까지 사람 중 한 명을 start 팀으로 선택
    for (int i = x; i < N; i++) {
        visited[i] = true;           // i번 사람을 start 팀에 넣고
        fun(i + 1, n + 1);            // 다음 사람 탐색 (중복 방지)
        visited[i] = false;          // 백트래킹 (원상 복구)
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;                        // 사람 수 입력

    // 능력치 행렬 입력
    team.assign(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> team[i][j];
        }
    }

    // start 팀 조합 탐색 시작
    fun(0, 0);

    // 최소 능력치 차이 출력
    cout << mn << "\n";

    return 0;
}

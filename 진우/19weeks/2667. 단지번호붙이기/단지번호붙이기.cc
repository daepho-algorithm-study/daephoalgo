#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[25][25];
bool visited[25][25] = { false };
vector<int> house;

int nx[4] = { -1, 0, 1, 0 };
int ny[4] = { 0, 1, 0, -1 };

int N;
int cnt;

// DFS 탐색
void dfs(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int nr = r + nx[i];
        int nc = c + ny[i];

        // 범위 체크
        if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

        // 아직 방문하지 않은 집이면
        if (!visited[nr][nc] && map[nr][nc] == 1) {
            visited[nr][nc] = true;
            cnt++;              // 집 개수 증가
            dfs(nr, nc);        // 재귀 탐색
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    // 지도 입력
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;  // 예: "0110100"
        for (int j = 0; j < N; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    // 전체 탐색
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                cnt = 1;                 // 단지 시작 → 1부터 카운트
                visited[i][j] = true;
                dfs(i, j);
                house.push_back(cnt);   // 단지 크기 저장
            }
        }
    }

    // 오름차순 정렬
    sort(house.begin(), house.end());

    // 단지 개수 출력
    cout << house.size() << "\n";

    // 각 단지 집 개수 출력
    for (int i = 0; i < house.size(); i++) {
        cout << house[i] << "\n";
    }

    return 0;
}

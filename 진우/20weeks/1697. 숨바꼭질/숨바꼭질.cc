#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, K;   // N: 시작 위치(수빈), K: 목표 위치(동생)

// visited[x] = x 위치까지 도달하는 데 걸린 최소 시간
// -1이면 아직 방문하지 않은 상태
vector<int> visited(100001, -1);

// BFS 함수: 시작 위치 n에서 목표 위치 K까지 최단 시간 탐색
void bfs(int n) {
    deque<int> q;          // BFS용 큐 (현재 위치 저장)

    // 시작 위치 방문 처리
    visited[n] = 0;        // 시작점은 시간 0
    q.push_back(n);        // 큐에 시작 위치 삽입

    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        int x = q.front(); // 현재 위치
        q.pop_front();

        // 목표 위치에 도착하면 즉시 종료
        // BFS 특성상 이때의 시간이 최단 시간
        if (x == K) return;

        // 현재 위치에서 x - 1 로 이동
        // 범위 안에 있고 아직 방문하지 않은 경우만 처리
        if (x - 1 >= 0 && visited[x - 1] == -1) {
            visited[x - 1] = visited[x] + 1; // 시간 +1
            q.push_back(x - 1);              // 큐에 추가
        }

        // 현재 위치에서 x + 1 로 이동
        if (x + 1 <= 100000 && visited[x + 1] == -1) {
            visited[x + 1] = visited[x] + 1;
            q.push_back(x + 1);
        }

        // 현재 위치에서 2 * x 로 순간이동
        if (2 * x <= 100000 && visited[2 * x] == -1) {
            visited[2 * x] = visited[x] + 1;
            q.push_back(2 * x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 시작 위치 N, 목표 위치 K 입력
    cin >> N >> K;

    // BFS 실행
    bfs(N);

    // 목표 위치 K까지 걸린 최단 시간 출력
    cout << visited[K] << "\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

// 각 정점의 인접 리스트 (그래프 저장)
vector<int> arr[100001];

// 방문 여부 체크 배열
bool visited[100001] = { false };

// 각 정점의 방문 순서를 저장할 배열
int result[100001] = { 0 };

// 방문 순서를 세는 카운터
int cnt = 0;

// BFS 함수
void bfs(int r) {
    deque<int> q;

    // 시작 정점을 큐에 넣고 방문 처리
    q.push_back(r);
    visited[r] = true;

    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        int node = q.front();   // 큐의 맨 앞 정점 꺼내기
        q.pop_front();

        // 방문 순서 기록
        cnt++;
        result[node] = cnt;

        // 현재 정점과 인접한 정점 탐색
        for (int i = 0; i < arr[node].size(); i++) {
            int nxt = arr[node][i];

            // 아직 방문하지 않은 정점이면 큐에 추가
            if (!visited[nxt]) {
                visited[nxt] = true;   // 큐에 넣는 순간 방문 처리 (중복 삽입 방지)
                q.push_back(nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, R;   // N: 정점 개수, M: 간선 개수, R: 시작 정점
    cin >> N >> M >> R;

    // 간선 입력 (무방향 그래프)
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    // 오름차순 방문을 위해 인접 리스트 정렬
    for (int i = 1; i <= N; i++) {
        sort(arr[i].begin(), arr[i].end());
    }

    // BFS 실행
    bfs(R);

    // 각 정점의 방문 순서 출력
    for (int i = 1; i <= N; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}

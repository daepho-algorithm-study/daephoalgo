#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 각 노드의 인접 노드를 저장할 배열
vector<int> arr[100001];

// 각 노드 방문 여부를 저장하는 배열
bool visited[100001];

// 각 노드의 부모 노드를 저장할 배열
int parent[100001];

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; // 노드 개수
    cin >> N;

    // 트리 간선 입력
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;

        // 무방향 그래프이므로 양쪽에 삽입
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    // BFS 탐색을 위한 큐 생성
    // 부모 정보를 배열에 저장하므로 큐에는 현재 노드만 넣어도 충분
    queue<int> q;

    q.push(1);         // 루트 노드 1 삽입
    visited[1] = true; // 루트 노드 방문 표시

    // BFS 시작
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // 현재 노드의 모든 인접 노드 탐색
        for (int i = 0; i < arr[node].size(); i++) {
            int next = arr[node][i];

            // 아직 방문하지 않은 노드라면
            if (!visited[next]) {
                visited[next] = true;       // 방문 표시
                parent[next] = node;   // 부모 노드를 현재 노드로 기록
                q.push(next);               // 다음 탐색을 위해 큐에 삽입
            }
        }
    }

    // 2번 노드부터 N번 노드까지 부모 출력
    for (int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
}
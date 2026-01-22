#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 인접 리스트 (정점 번호: 1 ~ N)
vector<int> arr[200001];

// 방문 여부 체크 배열
bool visited[200001] = {false};

// 각 정점의 방문 순서를 저장할 배열
int result[200001] = {0};

// 방문 순서를 매기기 위한 카운터
int cnt = 0;

// DFS 함수
void dfs(int r) {
    // 이미 방문한 정점이면 종료
    if (visited[r] == true) {
        return;
    }

    // 현재 정점을 방문 처리
    visited[r] = true;

    // 방문 순서 증가 후 저장
    cnt++;
    result[r] = cnt;

    // 현재 정점과 연결된 모든 정점 탐색
    for (int i = 0; i < (int)arr[r].size(); i++) {
        int nxt = arr[r][i];   // 다음 정점

        // 아직 방문하지 않았다면 DFS 진행
        if (!visited[nxt]) { 
            dfs(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, R;
    cin >> N >> M >> R;   // 정점 개수 N, 간선 개수 M, 시작 정점 R

    // 간선 정보 입력 (M개)
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        // 무방향 그래프이므로 양쪽에 추가
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    // 각 정점의 인접 리스트를 오름차순 정렬 (문제 조건)
    for (int i = 1; i <= N; i++) {
        sort(arr[i].begin(), arr[i].end());
    }

    // 시작 정점 R부터 DFS 실행
    dfs(R);

    // 각 정점의 방문 순서 출력
    for (int i = 1; i <= N; i++) {
        cout << result[i] << "\n";
    }
    
    return 0;
}

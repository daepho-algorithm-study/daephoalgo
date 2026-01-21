#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 각 정점의 인접 리스트 (그래프 저장)
vector<int> arr[100001];

// 방문 여부 체크 배열
bool visited[100001] = { false };

// 각 정점의 방문 순서를 저장할 배열
int result[100001] = {0};

// 방문 순서를 카운트하는 변수
int cnt = 0;

// 내림차순 정렬을 위한 비교 함수
bool compare(int a, int b) {
	return a > b;   // 큰 값이 앞에 오도록 정렬
}

// DFS 함수
void dfs(int r) {
	// 현재 정점을 방문 처리
	visited[r] = true;

	// 방문 순서 증가
	cnt++;
	result[r] = cnt;   // 현재 정점의 방문 순서 저장

	// 현재 정점과 연결된 모든 정점 탐색
	for (int i = 0; i < arr[r].size(); i++) {
		int nxt = arr[r][i];   // 다음 정점

		// 아직 방문하지 않은 정점이면 DFS 진행
		if (!visited[nxt]) {
			dfs(nxt);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, R;   // N: 정점 개수, M: 간선 개수, R: 시작 정점
	cin >> N >> M >> R;

	// 간선 입력 (무방향 그래프)
	for (int i = 1; i <= M; i++) {
		int u, v;
		cin >> u >> v;

		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	// 각 정점의 인접 리스트를 내림차순으로 정렬
	for (int i = 1; i <= N; i++) {
		sort(arr[i].begin(), arr[i].end(), compare);
	}

	// 시작 정점 R에서 DFS 실행
	dfs(R);

	// 각 정점의 방문 순서 출력
	for (int i = 1; i <= N; i++) {
		cout << result[i] << "\n";
	}
}

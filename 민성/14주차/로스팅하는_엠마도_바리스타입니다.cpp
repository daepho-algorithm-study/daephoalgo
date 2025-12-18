#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

// 연결 위치와 거리 저장 구조체 설정
struct node
{
    int idx, dist;
};

// 부모 자식 관계 결정 탐색 함수 정의
void dfs(int x);
// 서브 트리 값 계산 함수 정의
void subtree(int x);
// 최단 거리 합 계산 함수 정의
void calc(int x);

// 농장 연결 관계 저장 배열
vector<vector<node>> farm;
// 방문 체크 배열
vector<bool> visited;
// 부모 노드 저장 배열
vector<int> parent;
// 서브 트리 크기 저장 배열
vector<int> subsize;
// 서브 트리 거리 합 저장 배열
vector<ll> subsum;
// 해당 노드 기준 최단 거리 저장 배열
vector<ll> ans;
// 전역 변수로 입력값 개수 저장
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int u, v, d;
    cin >> n;
    // 배열 크기 할당
    farm.resize(n + 1), visited.resize(n + 1), parent.resize(n + 1);
    subsize.resize(n + 1), subsum.resize(n + 1), ans.resize(n + 1);
    // 농장 연결 정보 저장
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> d;
        farm[u].push_back({v, d});
        farm[v].push_back({u, d});
    }
    // root노드를 1로 설정
    parent[1] = 0;
    // 부모 자식 관계 설정
    dfs(1);
    // 서브 트리 정보 갱신
    subtree(1);
    // 1번 노드의 최단 거리 저장
    ans[1] = subsum[1];
    // 노드별 최단 거리 계산
    calc(1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << "\n";
    return 0;
}

void dfs(int x)
{
    // 방문 체크
    visited[x] = true;
    for (auto &e : farm[x])
    {
        // 자식 노드 할당
        int nxt = e.idx;
        // 이미 방문한 노드 스킵
        if (visited[nxt])
            continue;
        // 부모 노드 표시
        parent[nxt] = x;
        // 자식 노드를 부모로 가지는 노드 탐색
        dfs(nxt);
    }
}

void subtree(int x)
{
    // 자신을 서브트리 노드 개수에 합산
    subsize[x]++;
    for (auto &e : farm[x])
    {
        // 자식 노드와 거리 할당
        int nxt = e.idx, d = e.dist;
        // 부모 노드면 스킵
        if (parent[x] == nxt)
            continue;
        // 자식 노드의 자식 탐색
        subtree(nxt);
        // 자식 노드의 서브 트리 크기 합산
        subsize[x] += subsize[nxt];
        // 서브 트리 내 거리 합산
        // 자식 노드의 서브 트리 거리합 + 자식 노드와 부모 노드의 거리 * 자식 노드의 서브 트리 크기
        subsum[x] += subsum[nxt] + 1LL * subsize[nxt] * d;
    }
}

void calc(int x)
{
    for (auto &e : farm[x])
    {
        // 자식 노드와 거리 할당
        int nxt = e.idx, d = e.dist;
        // 부모 노드면 스킵
        if (parent[x] == nxt)
            continue;
        // 자식 노드 기준으로 계산할 때, 거리가 멀어진 노드와 가까워진 노드의 거리 계산
        // 가까워진 노드(-subsize), 멀어진 노드(n - subsize)
        ans[nxt] = ans[x] + d * (n - subsize[nxt] * 2);
        calc(nxt);
    }
}
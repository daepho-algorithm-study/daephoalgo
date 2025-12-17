#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 연결 노드 정보 저장 구조체 설정
struct node
{
    int op, d;
};

// 트리 구성 함수 정의
void maketree(int x);
// k번째 부모 노드 계산 함수 정의
int jump(int x, int k);
// 최소공통조상 탐색 함수 정의
int lca(int a, int b);

// 연결 정보 저장 배열
vector<vector<node>> v;
// 깊이 저장 배열
vector<int> depth;
// root와의 거리 저장 배열
vector<int> dist;
// 부모 노드 정보 저장 배열
vector<vector<int>> parent;
// 최대 깊이 설정(2^16 > 40000)
int mx = 16;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b, c;
    cin >> n;
    // 배열 크기 설정
    v.resize(n + 1), depth.resize(n + 1), dist.resize(n + 1);
    parent.resize(n + 1, vector<int>(mx));
    // 연결 정보 저장
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    // 1번 노드를 root로 설정한 트리 구성
    maketree(1);
    // 2^k번째 부모 노드 정보 저장
    for (int k = 1; k < mx; k++)
        for (int i = 1; i <= n; i++)
            parent[i][k] = parent[parent[i][k - 1]][k - 1];
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        // 최소공통조상(LCA) 할당
        int result = lca(a, b);
        // a와 b의 root 거리 합에서 LCA의 root 거리를 2번 빼주면 a와 b의 거리 계산 가능
        cout << dist[a] + dist[b] - 2 * dist[result] << "\n";
    }
    return 0;
}

void maketree(int x)
{
    for (auto e : v[x])
    {
        // 연결 노드 정보 할당
        int nxt = e.op, dis = e.d;
        // 부모 노드는 제외
        if (nxt == parent[x][0])
            continue;
        // 자식 노드와 부모 노드의 관계 저장
        parent[nxt][0] = x;
        dist[nxt] = dist[x] + dis;
        depth[nxt] = depth[x] + 1;
        maketree(nxt);
    }
}

int jump(int x, int k)
{
    // x가 root가 되거나 k번째 부모 노드를 탐색할 때까지 반복
    for (int i = 0; x && k; i++)
    {
        // 비트 연산으로 2^i번씩 점프
        if (k & 1)
            x = parent[x][i];
        k >>= 1;
    }
    return x;
}

int lca(int a, int b)
{
    // a와 b의 깊이가 다르면 같은 깊이로 조정
    if (depth[a] != depth[b])
    {
        // a를 깊이가 더 깊게 설정
        if (depth[a] < depth[b])
            swap(a, b);
        // a와 b의 깊이 차이만큼 점프
        a = jump(a, depth[a] - depth[b]);
    }
    // a와 b가 같다면 그 노드가 최소공통조상(LCA)
    if (a == b)
        return a;
    // 최소공통조상(LCA) 탐색
    for (int k = mx - 1; k >= 0; k--)
        if (parent[a][k] != parent[b][k])
        {
            a = parent[a][k];
            b = parent[b][k];
        }
    return parent[a][0];
}
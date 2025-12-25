#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 트리 탐색 함수 정의
void dfs(vector<vector<int>> &nd, vector<int> &dep, int x);
// 최소 공통 조상 출력 함수 정의
int lca(vector<int> dep, vector<int> p, int x, int y);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n;
        // 부모 노드 저장 배열
        vector<int> parent(n + 1, 0);
        // 노드 깊이 저장 배열
        vector<int> depth(n + 1, 0);
        // 연결 관계 저장 배열
        vector<vector<int>> node(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a >> b;
            // 연결 관계 저장
            node[a].push_back(b);
            // 부모 노드 정보 저장
            parent[b] = a;
        }
        // 루트 노드 저장 변수
        int root = 0;
        // 부모 노드가 없는 노드(root) 탐색
        for (int i = 1; i <= n; i++)
            if (parent[i] == 0)
            {
                root = i;
                break;
            }
        // 루트 노드부터 트리 전체 탐색 및 깊이 측정
        dfs(node, depth, root);
        cin >> a >> b;
        // 최소 공통 조상 탐색
        int ans = lca(depth, parent, a, b);
        cout << ans << "\n";
    }
    return 0;
}

void dfs(vector<vector<int>> &nd, vector<int> &dep, int x)
{
    for (int i = 0; i < nd[x].size(); i++)
    {
        // 자식 노드 할당
        int ch = nd[x][i];
        // 깊이 저장
        dep[ch] = dep[x] + 1;
        // 자식 노드를 대상으로 다시 탐색
        dfs(nd, dep, ch);
    }
}

int lca(vector<int> dep, vector<int> p, int x, int y)
{
    if (dep[x] != dep[y])
    {
        // 깊이가 높은 노드를 x에 배치
        if (dep[x] < dep[y])
            swap(x, y);
        // 깊이가 같아질 때까지 위로 이동
        while (dep[x] > dep[y])
            x = p[x];
    }
    // 노드가 만날 때까지 위로 이동
    while (x != y)
    {
        x = p[x];
        y = p[y];
    }
    return x;
}
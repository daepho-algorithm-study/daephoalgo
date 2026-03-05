#include <iostream>
#include <algorithm>

using namespace std;

// 루트 노드 탐색 함수 정의
int parent(int x);
// 병합 함수 정의
void merge(int x, int y);
// 루트 노드 저장 배열
int root[1000000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, m, k, a, b;
    cin >> t;
    for (int x = 1; x <= t; x++)
    {
        cin >> n >> k;
        // 루트 노드 배열 초기화
        for (int i = 0; i < n; i++)
            root[i] = i;
        // 친구 관계 저장(노드 병합)
        for (int i = 0; i < k; i++)
        {
            cin >> a >> b;
            merge(a, b);
        }
        cout << "Scenario " << x << ":\n";
        cin >> m;
        // 친구 관계 출력
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            // 루트 노드가 같으면 1, 아니면 0 출력
            if (parent(a) == parent(b))
                cout << 1;
            else
                cout << 0;
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}

int parent(int x)
{
    // 루트 노드를 탐색할 때까지 재귀 후 루트 노드 출력
    if (root[x] == x)
        return x;
    return root[x] = parent(root[x]);
}

void merge(int x, int y)
{
    // 각 노드의 루트 노드 할당
    x = parent(x), y = parent(y);
    // 루트 노드가 같다면 스킵
    if (x == y)
        return;
    // x가 y보다 작게 유지
    else if (x > y)
        swap(x, y);
    // 작은 쪽으로 루트 노드 통합
    root[y] = x;
}
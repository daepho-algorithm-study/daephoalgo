#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

struct pos
{
    int x, y, z; // 행성 좌표 저장 구조체 할당
};

int parent(int x);        // root 노드 탐색 함수 정의
bool merge(int x, int y); // 사이클 판단 및 병합 함수 정의
int root[100001];         // root 노드 저장 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pos> planet(n + 1);          // 행성 좌표 저장 배열
    vector<tuple<int, int, int>> edges; // 간선 좌표와 비용 저장 배열
    // 정렬을 위한 축별 좌표 저장 배열
    vector<pair<int, int>> x(n + 1), y(n + 1), z(n + 1);
    for (int i = 1; i <= n; i++)
    {
        // 행성 좌표와 원본 인덱스 저장
        cin >> planet[i].x >> planet[i].y >> planet[i].z;
        x[i].first = planet[i].x, y[i].first = planet[i].y, z[i].first = planet[i].z;
        x[i].second = i, y[i].second = i, z[i].second = i;
        root[i] = i; // 루트 노드 저장
    }
    sort(x.begin() + 1, x.end());
    sort(y.begin() + 1, y.end()); // 축별로 좌표 정렬
    sort(z.begin() + 1, z.end());
    for (int i = 1; i < n; i++)
    {
        // 정렬된 인접 좌표 두 개 할당
        int a = x[i].second, b = x[i + 1].second;
        // 간선 정보 저장
        edges.push_back({abs(x[i].first - x[i + 1].first), a, b});
        a = y[i].second, b = y[i + 1].second;
        edges.push_back({abs(y[i].first - y[i + 1].first), a, b});
        a = z[i].second, b = z[i + 1].second;
        edges.push_back({abs(z[i].first - z[i + 1].first), a, b});
    }
    sort(edges.begin(), edges.end());
    long long sm = 0; // 비용 합산 변수
    for (int i = 0; i < edges.size(); i++)
    {
        int a = get<1>(edges[i]), b = get<2>(edges[i]); // 인덱스 할당
        if (merge(a, b))
            sm += get<0>(edges[i]); // 사이클 미생성 시 간선 합산
    }
    cout << sm;
    return 0;
}

int parent(int x)
{
    if (root[x] == x)
        return x;                     // root 노드 탐색 완료 시 리턴
    return root[x] = parent(root[x]); // root 찾을 때까지 탐색
}

bool merge(int x, int y)
{
    x = parent(x), y = parent(y); // 각 root 노드 할당
    if (x == y)
        return false; // 사이클 생성 시 false 반환
    if (x > y)
        swap(x, y);
    root[y] = x; // 사이클 미생성 시 노드 병합
    return true;
}
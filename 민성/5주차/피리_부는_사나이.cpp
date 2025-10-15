#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

int find(int x);                                  // 루트 노드 탐색 함수 정의
void unite(int x, int y);                         // 노드 병합 함수 정의
int root[1000000];                                // 루트 노드 체크 배열
string dir[1000];                                 // 방향 저장 배열
unordered_map<char, int> d;                       // 방향 체크 해시
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}; // 델타 탐색 변수
set<int> ans;                                     // 집합 개수 판별 set

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    d['U'] = 0, d['D'] = 1, d['L'] = 2, d['R'] = 3; // 방향 설정
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> dir[i]; // 방향 저장
        for (int j = 0; j < m; j++)
            root[i * m + j] = i * m + j; // 각각의 루트 번호 저장
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int k = d[dir[i][j]];               // 방향 번호 할당
            int nx = i + dx[k], ny = j + dy[k]; // 이동 위치 할당
            unite(i * m + j, nx * m + ny);      // 이동 위치와 병합
        }
    for (int i = 0; i < n * m; i++)
        ans.insert(find(i));
    cout << ans.size();
    return 0;
}

int find(int x)
{
    if (root[x] == x)
        return x;                   // 루트 노드일 때 출력
    return root[x] = find(root[x]); // 루트 노드를 찾을때까지 탐색
}

void unite(int x, int y)
{
    x = find(x), y = find(y); // 각 수의 루트 노드 할당
    if (x == y)
        return;
    else if (x < y)
        root[y] = x; // 작은 수 쪽으로 병합
    else
        root[x] = y;
}
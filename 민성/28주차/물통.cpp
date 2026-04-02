#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

// A, B 물통값 변동 함수 정의
void wm(int na, int nb);
// A, B 상태에 따른 방문 체크 배열과 C값 체크 배열
bool visited[201][201], ans[201];
// 너비 탐색 구현 큐 할당
queue<pair<int, int>> q;
int a, b, c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c;
    // 초기 상태 큐에 삽입
    q.push({0, 0});
    // 방문 체크
    visited[0][0] = true;
    // C값 체크
    ans[c] = true;
    // 큐가 빌 때까지 반복
    while (!q.empty())
    {
        // A, B, C 물통 현재 상태 할당
        int ca = q.front().first, cb = q.front().second, cc = c - ca - cb;
        q.pop();
        // A->B로 물 이동
        int dif = min(ca, b - cb);
        wm(ca - dif, cb + dif);
        // A->C
        dif = min(ca, c - cc);
        wm(ca - dif, cb);
        // B->A
        dif = min(cb, a - ca);
        wm(ca + dif, cb - dif);
        // B->C
        dif = min(cb, c - cc);
        wm(ca, cb - dif);
        // C->A
        dif = min(cc, a - ca);
        wm(ca + dif, cb);
        // C->B
        dif = min(cc, b - cb);
        wm(ca, cb + dif);
    }
    for (int i = 0; i <= c; i++)
        if (ans[i])
            cout << i << " ";
    return 0;
}

void wm(int na, int nb)
{
    // 방문했었으면 스킵
    if (visited[na][nb])
        return;
    visited[na][nb] = true;
    q.push({na, nb});
    // 물 이동 후 C 물통값 할당
    int nc = c - na - nb;
    // A 물통값이 0일 때 C 물통값 체크
    if (na == 0)
        ans[nc] = true;
}
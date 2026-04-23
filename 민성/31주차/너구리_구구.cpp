#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b, c;
    cin >> n;
    // 각 방 사이 거리 저장 배열 할당
    vector<vector<pair<int, int>>> room(n + 1);
    // 방문 체크 배열 할당
    vector<bool> visited(n + 1, false);
    // 거리 저장 배열 할당
    vector<long long> d(n + 1, 0);
    // bfs 구현 큐 할당
    queue<int> q;
    // 방 사이 거리 정보 저장
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> c;
        room[a].push_back({b, c});
        room[b].push_back({a, c});
    }
    // 시작점 삽입
    q.push(1);
    // 시작점 방문 체크
    visited[1] = true;
    while (!q.empty())
    {
        // 현재 위치 할당
        int x = q.front();
        q.pop();
        for (int i = 0; i < room[x].size(); i++)
        {
            // 다음 위치 할당
            int nxt = room[x][i].first;
            // 방문하지 않은 위치로 이동
            if (!visited[nxt])
            {
                // 거리 합산
                d[nxt] = d[x] + room[x][i].second;
                // 방문 체크
                visited[nxt] = true;
                // 큐에 이동 위치 삽입
                q.push(nxt);
            }
        }
    }
    // 최대값 저장 변수 할당
    long long mx = 0;
    // 최대값 갱신
    for (int i = 1; i <= n; i++)
        if (mx < d[i])
            mx = d[i];
    cout << mx;
    return 0;
}
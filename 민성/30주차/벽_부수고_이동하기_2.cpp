#include <iostream>
#include <queue>

using namespace std;

// 맵 위치와 부순 벽 개수 저장 구조체 정의
struct pos
{
    int x, y, w = 0;
};

// 맵 정보 배열 할당과 방문 배열 할당
bool mp[1001][1001], visited[1001][1001][11];
// 델타 탐색 변수 할당
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 최단 경로 저장 변수
    int n, m, k, cnt = 1;
    string s;
    // bfs 구성 큐 할당
    queue<pos> q;
    cin >> n >> m >> k;
    // 맵 정보 저장
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 1; j <= m; j++)
            mp[i][j] = s[j - 1] - '0';
    }
    // 초기값 할당
    q.push({1, 1, 0});
    visited[1][1][0] = true;
    while (!q.empty())
    {
        // 현재 큐 크기 할당
        int qs = q.size();
        // 현재 큐 크기만큼만 탐색
        for (int j = 0; j < qs; j++)
        {
            // 현재 상태 할당
            int cx = q.front().x, cy = q.front().y, cw = q.front().w;
            q.pop();
            // 목적지 도달 시 최단 경로 출력 후 종료
            if (cx == n && cy == m)
            {
                cout << cnt;
                return 0;
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = cx + dx[i], ny = cy + dy[i];
                // 범위 밖 제외
                if (nx <= 0 || nx > n || ny <= 0 || ny > m)
                    continue;
                // 벽이면 부술 수 있을 때만 경로 탐색
                if (mp[nx][ny] == 1)
                {
                    // 벽을 부술 수 없으면 스킵
                    if (cw >= k)
                        continue;
                    // 방문한 곳 제외
                    if (visited[nx][ny][cw + 1])
                        continue;
                    q.push({nx, ny, cw + 1});
                    visited[nx][ny][cw + 1] = true;
                    continue;
                }
                // 방문한 곳 제외
                if (visited[nx][ny][cw])
                    continue;
                // 벽이 아닌 곳은 그대로 경로 탐색
                q.push({nx, ny, cw});
                visited[nx][ny][cw] = true;
            }
        }
        // 경로 카운팅
        cnt++;
    }
    // 목적지 도달 불가 시 -1 출력
    cout << -1;
    return 0;
}
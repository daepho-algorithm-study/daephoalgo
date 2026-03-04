#include <iostream>
#include <queue>
#include <string>

using namespace std;

// 정보섬 정보 저장 배열
int land[3000][3000];
// 방문 체크 배열
bool visited[3000][3000];
// 델타 탐색 변수
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 최단 거리 누적 변수 할당
    int n, m, cnt = 0;
    string s;
    // bfs 구현 큐 할당
    queue<pair<int, int>> q;
    cin >> n >> m;
    // 정보섬 정보 저장
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            land[i][j] = s[j] - '0';
            // 시작 위치 큐에 삽입
            if (land[i][j] == 2)
            {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    // 큐가 빌 때까지 bfs탐색
    while (!q.empty())
    {
        // 현재 큐 크기 할당
        int qs = q.size();
        // 거리 합산
        cnt++;
        for (int i = 0; i < qs; i++)
        {
            // 현재 위치 할당
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                // 탐색 대상 위치 할당
                int nx = x + dx[k], ny = y + dy[k];
                // 탐색 범위 초과 시 제외
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                // 방문한 위치거나 장애물 위치 제외
                if (visited[nx][ny] || land[nx][ny] == 1)
                    continue;
                // 음식에 도착 시 최단거리 출력 후 종료
                if (land[nx][ny] != 0)
                {
                    cout << "TAK" << "\n"
                         << cnt;
                    return 0;
                }
                // 경로 큐에 삽입
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    cout << "NIE";
    return 0;
}
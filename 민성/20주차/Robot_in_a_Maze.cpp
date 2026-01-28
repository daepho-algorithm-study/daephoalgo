#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

// 델타 탐색 변수
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
// 미로 정보 저장 배열
string maze[15];
// 방문 체크 배열
bool visited[15][15];
// 시작점 위치 저장 변수
pair<int, int> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, r, c;
    cin >> n;
    while (n--)
    {
        cin >> r >> c;
        // 미로 정보 저장
        for (int i = 0; i < r; i++)
        {
            cin >> maze[i];
            for (int j = 0; j < c; j++)
            {
                // 방문 체크 배열 초기화
                visited[i][j] = false;
                // 시작점 위치 저장
                if (maze[i][j] == 'S')
                    s = {i, j};
            }
        }
        // BFS 탐색 큐 할당
        queue<pair<int, int>> q;
        // 최소 이동 횟수 저장 변수
        int t = 0;
        // 탈출 체크 변수
        bool check = false;
        // 시작점을 큐에 할당
        q.push(s);
        // 방문 체크
        visited[s.first][s.second] = true;
        // 탈출하거나 이동 불가할 때까지 탐색
        while (!q.empty() && !check)
        {
            // 이동 횟수 카운팅
            t++;
            // 같은 깊이 위치 개수 저장
            int ln = q.size();
            // 같은 깊이 위치 탐색
            while (ln-- && !check)
            {
                // 현재 위치 할당
                int x = q.front().first, y = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k], ny = y + dy[k];
                    // 벽위치거나 방문한 곳 제외
                    if (maze[nx][ny] == 'X' || visited[nx][ny] == true)
                        continue;
                    // 목표 지점 도달 시 탈출 체크
                    if (maze[nx][ny] == 'G')
                    {
                        check = true;
                        break;
                    }
                    // 다음 탐색 위치 큐에 삽입
                    q.push({nx, ny});
                    // 방문 체크
                    visited[nx][ny] = true;
                }
            }
        }
        if (check)
            cout << "Shortest Path: " << t;
        else
            cout << "No Exit";
        cout << "\n";
    }
    return 0;
}
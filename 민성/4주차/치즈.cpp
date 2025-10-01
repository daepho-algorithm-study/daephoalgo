#include <iostream>
#include <queue>

using namespace std;

void air(int x, int y);                           // 외부 공기 함수 정의
queue<pair<int, int>> q;                          // 치즈 위치 저장 큐
queue<pair<int, int>> a;                          // 빈 공간 저장 큐
int cheese[100][100];                             // 치즈 위치 저장 배열
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; // 델타 탐색 변수
int n, m, t = 0;                                  // 시간 체크 변수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> cheese[i][j]; // 치즈 위치 저장
            if (cheese[i][j] == 1)
                q.push({i, j}); // 치즈 위치 큐에 삽입
        }
    air(0, 0); // 외부 공기 표시
    while (!q.empty())
    {
        t++; // 시간 증가
        int qs = q.size();
        for (int i = 0; i < qs; i++)
        {
            int x = q.front().first, y = q.front().second; // 치즈 위치 할당
            int cnt = 0;                                   // 외부 공기 카운팅 변수
            q.pop();
            for (int j = 0; j < 4; j++)
            {
                int nx = x + dx[j], ny = y + dy[j]; // 사방 탐색
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue; // 범위 외 제외
                if (cheese[nx][ny] == -1)
                    cnt++; // 외부 공기 카운팅
            }
            if (cnt >= 2)
            {
                cheese[x][y] = 0; // 빈 공간으로 할당
                a.push({x, y});   // 빈 공간 저장 큐에 저장
            }
            else
                q.push({x, y}); // 다시 큐에 저장
        }
        while (!a.empty())
        {
            int x = a.front().first, y = a.front().second; // 빈 공간 위치 할당
            a.pop();
            air(x, y); // 외부 공기 체크
        }
    }
    cout << t;
    return 0;
}

void air(int x, int y)
{
    cheese[x][y] = -1; // 외부 공기 표시
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i]; // 탐색 위치 저장
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue; // 범위 외 제외
        if (!cheese[nx][ny])
            air(nx, ny); // 탐색하지 않은 위치 탐색
    }
}
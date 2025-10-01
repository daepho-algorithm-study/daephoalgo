#include <iostream>
#include <vector>

using namespace std;

void bt(int cur, int cnt);                        // 백트래킹 함수 정의
void dfs(int x, int y);                           // 탐색을 위한 dfs 정의
int lab[8][8];                                    // 연구실 공간 저장 배열
bool visited[8][8];                               // 방문 체크 배열
vector<pair<int, int>> virus;                     // 바이러스 위치 저장 배열
vector<pair<int, int>> load;                      // 빈 공간 위치 저장 배열
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; // 델타 탐색 변수
int n, m, mx = 0;                                 // 최대 안전 영역 크기 저장 변수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> lab[i][j]; // 연구소 배치 저장
            if (!lab[i][j])
                load.push_back({i, j});
            else if (lab[i][j] == 2)
                virus.push_back({i, j}); // 바이러스 위치 저장
        }
    bt(0, 0);
    cout << mx;
    return 0;
}

void bt(int cur, int cnt)
{
    if (cnt == 3) // 임의의 벽 3개 설치 시
    {
        for (int i = 0; i < virus.size(); i++)
        {
            int x = virus[i].first, y = virus[i].second;
            dfs(x, y); // 바이러스 확산
        }
        int v_cnt = 0; // 확산된 바이러스 카운팅 변수
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (visited[i][j]) // 바이러스가 퍼진 위치일 때
                {
                    v_cnt++;               // 바이러스 카운팅
                    visited[i][j] = false; // 방문 해제
                }
        int safe = load.size() - v_cnt - 3; // 안전 구역 크기 저장
        if (mx < safe)
            mx = safe; // 안전 구역 최대 크기 갱신
        return;
    }
    for (int i = cur; i < load.size(); i++)
    {
        int x = load[i].first, y = load[i].second;
        lab[x][y] = 1;        // 해당 위치에 벽 설치
        bt(i + 1, cnt + 1); // 다른 빈 공간에 벽 설치를 위해 탐색
        lab[x][y] = 0;        // 탐색 완료 후 다시 벽 철거
    }
}

void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i]; // 다음 탐색 위치
        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            if (!lab[nx][ny] && !visited[nx][ny])
            {
                visited[nx][ny] = true; // 방문 체크
                dfs(nx, ny);
            }
    }
}
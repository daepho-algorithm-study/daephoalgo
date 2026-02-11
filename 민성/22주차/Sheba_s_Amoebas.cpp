#include <iostream>

using namespace std;

// dfs 탐색 함수 정의
void dfs(int x, int y);

// 접시 정보 저장 배열
string dish[100];
// 방문 체크 배열
bool visited[100][100];
// 8방향 탐색 변수
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};
// 아메바 수 카운팅 변수
int m, n, ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    // 접시 정보 저장
    for (int i = 0; i < m; i++)
        cin >> dish[i];
    // 접시에서 아메바 수 탐색
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (dish[i][j] == '#' && !visited[i][j])
            {
                // 아메바 수 카운팅
                ans++;
                visited[i][j] = true;
                // 같은 아메바 픽셀 체크
                dfs(i, j);
            }
    cout << ans;
    return 0;
}

void dfs(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        // 다음 탐색 위치 할당
        int nx = x + dx[i], ny = y + dy[i];
        // 범위 이탈 시 스킵
        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
        // 하얀 픽셀이거나 이미 방문한 위치면 스킵
        if (dish[nx][ny] == '.' || visited[nx][ny])
            continue;
        // 방문 체크 후 다음 위치 탐색
        visited[nx][ny] = true;
        dfs(nx, ny);
    }
}
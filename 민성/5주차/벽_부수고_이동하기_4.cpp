#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; // 델타 탐색 변수
int area[1000000];                                // 영역 크기 저장 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, num = 2; // 영역 구별 변수
    string st;
    queue<pair<int, int>> q; // bfs용 큐 할당
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m)); // 맵 정보 저장 배열
    vector<vector<int>> w(n, vector<int>(m)); // 영역 정보 저장 배열
    for (int i = 0; i < n; i++)
    {
        cin >> st;
        for (int j = 0; j < m; j++)
        {
            v[i][j] = st[j] - '0'; // 맵 정보 입력
            w[i][j] = v[i][j];
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (w[i][j] == 0)
            {
                int cnt = 1;   // 영역 크기 카운팅 변수
                w[i][j] = num; // 초기 위치 영역 설정
                q.push({i, j});
                while (!q.empty())
                {
                    int x = q.front().first, y = q.front().second; // 위치 할당
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k], ny = y + dy[k]; // 탐색 위치 할당
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && w[nx][ny] == 0)
                        {
                            w[nx][ny] = num;  // 빈 공간 영역 할당
                            cnt++;            // 영역 추가
                            q.push({nx, ny}); // 탐색을 위해 큐 삽입
                        }
                    }
                }
                area[num] = cnt; // 영역 크기 저장
                num++;           // 다음 영역 할당
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j] == 1)
            {
                set<int> s; // 인접 영역 체크 set
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k], ny = j + dy[k]; // 탐색 위치 할당
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && w[nx][ny] > 1)
                        s.insert(w[nx][ny]); // 인접 영역 체크
                }
                for (auto k : s)
                    v[i][j] += area[k]; // 인접 영역 크기 합산
            }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << v[i][j] % 10;
        cout << "\n";
    }

    return 0;
}
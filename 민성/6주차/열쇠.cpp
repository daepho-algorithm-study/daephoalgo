#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; // 델타 탐색 변수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<pair<int, int>>> door(26); // 문 위치 저장 배열
        queue<pair<int, int>> q;                 // bfs용 큐 할당
        bool key[26] = {false};                  // 보유한 열쇠 체크 배열
        int h, w, cnt = 0;                       // 문서 카운팅 변수
        string s;
        cin >> h >> w;
        // 외곽이 '.'로 채워진 지도 생성
        vector<string> m(h + 2, string(w + 2, '.'));
        // 방문 체크 배열
        vector<vector<bool>> visited(h + 2, vector<bool>(w + 2, false));
        for (int i = 1; i <= h; i++)
        {
            cin >> s;
            m[i].replace(1, w, s); // 지도 작성
        }
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                break;              // 열쇠가 없는 경우는 스킵
            key[s[i] - 'a'] = true; // 보유한 열쇠 체크
        }
        q.push({0, 0});       // 외곽에서 시작
        visited[0][0] = true; // 방문 체크
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second; // 현재 위치 할당
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i]; // 다음 탐색 위치 할당
                if (nx >= 0 && nx <= h + 1 && ny >= 0 && ny <= w + 1 && !visited[nx][ny])
                {
                    char c = m[nx][ny];
                    if (c == '*')
                        continue; // 벽이면 스킵
                    if (c >= 'A' && c <= 'Z')
                    {
                        int k = c - 'A';
                        if (!key[k])
                        {
                            door[k].push_back({nx, ny}); // 해당 문 대기
                            continue;
                        }
                    }
                    if (c >= 'a' && c <= 'z')
                    {
                        int k = c - 'a';
                        if (!key[k])
                        {
                            key[k] = true; // 키 체크
                            for (auto const &p : door[k])
                                q.push(p); // 대기하던 문 큐에 삽입
                        }
                    }
                    if (c == '$')
                        cnt++;              // 문서 발견 시 카운팅
                    visited[nx][ny] = true; // 방문 체크
                    q.push({nx, ny});
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
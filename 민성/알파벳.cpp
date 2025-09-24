#include <iostream>
#include <string>

using namespace std;
void bt(int x, int y, int cnt);                   // 백트래킹 정의 함수
bool check[26];                                   // 알파벳 체크 함수
bool visited[20][20];                             // 위치 방문 체크 함수
string alpha[20];                                 // 위치 저장 배열
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; // 델타 탐색 변수
int r, c, mx = 0;                                 // 최대 이동 칸 저장 변수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        cin >> alpha[i];
    bt(0, 0, 1);
    cout << mx;
    return 0;
}

void bt(int x, int y, int cnt)
{
    visited[x][y] = true;           // 방문 체크
    check[alpha[x][y] - 65] = true; // 알파벳 체크
    bool pos = false;               // 이동 가능 위치 존재 여부 체크 변수
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i]; // 다음 이동 위치 저장
        if (nx >= 0 && nx < r && ny >= 0 && ny < c)
        {
            char c = alpha[nx][ny]; // 다음 위치의 알파벳 저장
            if (!visited[nx][ny] && !check[c - 65])
            {
                pos = true;
                bt(nx, ny, cnt + 1); // 이동 가능한 위치 탐색
                visited[nx][ny] = false;
                check[c - 65] = false;
            }
        }
    }
    if (!pos && mx < cnt)
        mx = cnt; // 이동이 더 이상 불가할 때 최대값 갱신
}
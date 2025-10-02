#include <iostream>
#include <vector>

using namespace std;

int dust[50][50];                                 // 미세먼지 양 저장 배열
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; // 델타 탐색 변수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r, c, t;
    vector<int> filter; // 공기청정기 위치 저장 배열
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            cin >> dust[i][j]; // 미세먼지 양 저장
            if (dust[i][j] == -1)
                filter.push_back(i); // 공기 청정기 r좌표 저장
        }
    for (int i = 0; i < t; i++)
    {
        int temp[50][50] = {0};
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                int cnt = 0; // 확산 가능 방향 카운팅 변수
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k], ny = j + dy[k]; // 사방 탐색
                    if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                        continue; // 범위 밖 제외
                    if (dust[nx][ny] == -1)
                        continue;                   // 공기청정기 제외
                    temp[nx][ny] += dust[i][j] / 5; // 미세먼지 확산 저장
                    cnt++;                          // 확산 방향 카운팅
                }
                temp[i][j] -= (dust[i][j] / 5) * cnt; // 확산된 만큼 먼지 제거
            }
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                dust[i][j] += temp[i][j];         // 미세먼지 확산 적용
        int left = 0, right = dust[filter[0]][1]; // 순환할 먼지 양 저장 변수
        for (int i = 1; i < c - 1; i++)
        {
            dust[filter[0]][i] = left;
            left = right;
            right = dust[filter[0]][i + 1];
        }
        for (int i = filter[0]; i > 0; i--)
        {
            dust[i][c - 1] = left;
            left = right;
            right = dust[i - 1][c - 1];
        }
        for (int i = c - 1; i > 0; i--) // 반시계 순환
        {
            dust[0][i] = left;
            left = right;
            right = dust[0][i - 1];
        }
        for (int i = 0; i < filter[0]; i++)
        {
            dust[i][0] = left;
            left = right;
            right = dust[i + 1][0];
        }
        left = 0, right = dust[filter[1]][1];
        for (int i = 1; i < c - 1; i++)
        {
            dust[filter[1]][i] = left;
            left = right;
            right = dust[filter[1]][i + 1];
        }
        for (int i = filter[1]; i < r - 1; i++)
        {
            dust[i][c - 1] = left;
            left = right;
            right = dust[i + 1][c - 1];
        }
        for (int i = c - 1; i > 0; i--) // 시계 순환
        {
            dust[r - 1][i] = left;
            left = right;
            right = dust[r - 1][i - 1];
        }
        for (int i = r - 1; i > filter[1]; i--)
        {
            dust[i][0] = left;
            left = right;
            right = dust[i - 1][0];
        }
    }
    int sm = 0; // 남아있는 미세먼지 양 저장 변수
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            sm += dust[i][j]; // 미세먼지 양 합산
    sm += 2; // 공기청정기 제외
    cout << sm;
    return 0;
}
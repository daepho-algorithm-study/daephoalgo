#include <iostream>

using namespace std;
int home[16][16]; // 집 벽 위치 저장 배열
int col[16][16];  // 세로 파이프 누적 저장 배열
int row[16][16];  // 가로 파이프 누적 저장 배열
int dia[16][16];  // 대각선 파이프 누적 저장 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> home[i][j]; // 벽 위치 저장
    row[0][1] = 1;             // 초기 파이프 저장
    for (int j = 2; j < n; ++j)
        if (!home[0][j])
            row[0][j] = row[0][j - 1]; // 가로 첫 줄 누적
    for (int i = 1; i < n; i++)
        for (int j = 2; j < n; j++)
            if (home[i][j] != 1) // 해당 위치가 벽이 아닐 때만 누적
            {
                row[i][j] = row[i][j - 1] + dia[i][j - 1]; // 가로 파이프 경우의 수 누적
                col[i][j] = dia[i - 1][j] + col[i - 1][j]; // 세로 파이프 경우의 수 누적
                // 대각선 파이프가 설치 가능할 때
                if (!home[i - 1][j] && !home[i][j - 1])
                    dia[i][j] = row[i - 1][j - 1] + dia[i - 1][j - 1] + col[i - 1][j - 1];
            }
    // (N, N) 지점 파이프 설치 경우의 수 합산
    int sm = row[n - 1][n - 1] + dia[n - 1][n - 1] + col[n - 1][n - 1];
    cout << sm;
    return 0;
}
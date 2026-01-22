#include <iostream>
#include <string>

using namespace std;

// 바둑판 정보 저장 배열
string board[10];
// 바둑판 상하좌우 반전 저장 배열
string xy[10];
// 바둑판 대각선 정보 저장 배열
string diag1[19], diag2[19];
// 탐색 대상 저장 배열
string s[5] = {".XXXX", "X.XXX", "XX.XX", "XXX.X", "XXXX."};
// 오목 가능성 판별 함수 정의
bool concave(string &c, string f[5]);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 바둑판 정보 저장
    for (int i = 0; i < 10; i++)
        cin >> board[i];
    // 오목 가능 여부 체크 변수
    bool check = false;
    // 바둑판 상하좌우 반전 정보 저장
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            xy[i] += board[j][i];
    // 바둑판 대각선 정보 저장
    for (int k = -9; k < 10; k++)
        for (int i = 0; i < 10; i++)
            if (i + k >= 0 && i + k < 10)
                diag1[k + 9] += board[i][i + k];
    for (int k = 0; k < 19; k++)
        for (int i = 0; i < 10; i++)
            if (k - i >= 0 && k - i < 10)
                diag2[k] += board[i][k - i];
    // 가로 세로 오목 판별
    for (int i = 0; i < 10; i++)
        if (concave(board[i], s) || concave(xy[i], s))
        {
            cout << 1;
            return 0;
        }
    // 대각선 오목 판별
    for (int i = 0; i < 19; i++)
        if (concave(diag1[i], s) || concave(diag2[i], s))
        {
            cout << 1;
            return 0;
        }
    // 오목 불가능 시 0 출력
    cout << 0;
    return 0;
}

bool concave(string &c, string f[5])
{
    for (int i = 0; i < 5; i++)
        if (c.find(f[i]) != string::npos)
            return true;
    return false;
}
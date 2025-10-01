#include <iostream>

using namespace std;
void recursion(int x, int y, int h); // 별 찍기 패턴 구현을 위한 재귀 함수 정의
char star[3100][6200];               // 별 찍기 좌표 저장 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < 2 * n; j++)
            star[i][j] = ' ';
    recursion(1, n, n); // 가장 큰 삼각형의 제일 위쪽 꼭짓점부터 재귀 시작
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < 2 * n; j++)
            cout << star[i][j]; // 패턴이 찍힌 배열 출력
        cout << "\n";
    }
    return 0;
}

void recursion(int x, int y, int h)
{
    if (h == 3)
    {
        star[x][y] = '*';
        star[x + 1][y - 1] = '*';
        star[x + 1][y + 1] = '*'; // 높이 3인 기초 패턴 찍기
        for (int i = 0; i < 5; i++)
            star[x + 2][y - i + 2] = '*';
    }
    else
    {
        int half = h / 2;
        recursion(x, y, half);
        recursion(x + half, y - half, half); // 높이가 h/2인 삼각형 세 개를 재탐색
        recursion(x + half, y + half, half);
    }
}
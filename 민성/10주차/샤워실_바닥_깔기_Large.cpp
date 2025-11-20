#include <iostream>
#include <utility>

using namespace std;

// 트로미노 타일링 알고리즘 함수 정의
void tromino(int sr, int sc, int size, pair<int, int> h);
void painting(int r, int c, int flag); // 트로미노 타일 색칠 함수 정의
int tile[129][129];                    // 타일 배치 저장 배열
int num = 0;                           // 타일 번호 변수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, x, y;
    cin >> k >> x >> y;
    int s = 1 << k;  // 크기 저장
    tile[y][x] = -1; // 구멍 표시
    tromino(1, 1, s, {y, x});
    for (int i = s; i >= 1; i--)
    {
        for (int j = 1; j <= s; j++)
            cout << tile[i][j] << " ";
        cout << "\n";
    }
    return 0;
}

void tromino(int sr, int sc, int size, pair<int, int> h)
{
    if (size == 1)
        return; // 크기 1 타일이면 스킵
    // 타일 중간 좌표 할당
    int mr = sr + size / 2, mc = sc + size / 2;
    // 각 사분면에서의 구멍 좌표
    pair<int, int> h1 = {mr - 1, mc - 1};
    pair<int, int> h2 = {mr - 1, mc};
    pair<int, int> h3 = {mr, mc - 1};
    pair<int, int> h4 = {mr, mc};
    if (h.first < mr && h.second < mc)
    {
        // 사분면에 구멍이 존재하면 기존 구멍 좌표를 할당
        painting(mr, mc, 1);
        h1.first = h.first, h1.second = h.second;
    }
    if (h.first < mr && h.second >= mc)
    {
        // 사분면에 구멍이 존재하면 기존 구멍 좌표를 할당
        painting(mr, mc, 2);
        h2.first = h.first, h2.second = h.second;
    }
    if (h.first >= mr && h.second < mc)
    {
        // 사분면에 구멍이 존재하면 기존 구멍 좌표를 할당
        painting(mr, mc, 3);
        h3.first = h.first, h3.second = h.second;
    }
    if (h.first >= mr && h.second >= mc)
    {
        // 사분면에 구멍이 존재하면 기존 구멍 좌표를 할당
        painting(mr, mc, 4);
        h4.first = h.first, h4.second = h.second;
    }
    // 4분할 한 타일을 다시 탐색
    tromino(sr, sc, size / 2, h1);
    tromino(sr, mc, size / 2, h2);
    tromino(mr, sc, size / 2, h3);
    tromino(mr, mc, size / 2, h4);
}

void painting(int r, int c, int flag)
{
    num++;
    if (flag != 1)
        tile[r - 1][c - 1] = num;
    if (flag != 2)
        tile[r - 1][c] = num;
    if (flag != 3) // 구멍이 존재하는 사분면 제외 타일 색칠
        tile[r][c - 1] = num;
    if (flag != 4)
        tile[r][c] = num;
}
#include <iostream>
#include <algorithm>

using namespace std;

// '/' 대각선 탐색 함수 정의
void bt(int idx, int cnt);
int board[10][10]; // 체스판 상태 저장 배열
bool visited[20];  // '\' 대각선 체크 배열
int n, mx = 0;     // 비숍 최대값 저장 변수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w, b; // 흰색, 검은색 칸 비숍 최대값 저장 변수
    cin >> n;
    // 해당 대각선 비숍 유무 체크 배열
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j]; // 체스판 초기 상태 저장

    bt(0, 0); // 흰색 칸 탐색
    w = mx;
    mx = 0;   // 최대값 변수 초기화
    bt(1, 0); // 검은색 칸 탐색
    b = mx;
    cout << w + b;
    return 0;
}

void bt(int s, int cnt)
{
    if (s > n * 2 - 2)
    {
        mx = max(mx, cnt); // 탐색 완료 시 최대값 갱신
        return;
    }
    bt(s + 2, cnt); // 대각선에 아무것도 두지 않고 넘어가는 경우
    // 대각선 절반을 넘어갔을 때를 고려한 시작점과 끝점 할당
    int rs = max(0, s - (n - 1)), re = min(n - 1, s);
    for (int r = rs; r <= re; r++)
    {
        int c = s - r; // 이동 변수 할당
        if (board[r][c] != 1)
            continue;            // 비숍을 못 두는 위치는 스킵
        int d = r - c + (n - 1); // '\ 대각선 체크 변수 할당
        if (visited[d])
            continue;       // 해당 대각선 사용 시 스킵
        visited[d] = true;  // 해당 대각선 사용
        bt(s + 2, cnt + 1); // 다음 탐색 시작
        visited[d] = false; // 대각선 할당 해제
    }
}
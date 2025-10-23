#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct state
{
    int rx, ry, bx, by, cnt = 0; // 공 위치 저장 구조체 할당
};
// 공 굴리기 함수 정의
pair<int, int> roll(const vector<string> &board, int x, int y, int dir, int &step, bool &hole);
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; // 델타 탐색 변수
bool visited[10][10][10][10];                     // 방문 체크 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<string> board(n); // 보드 정보 저장 배열
    for (int i = 0; i < n; i++)
        cin >> board[i]; // 보드 정보 저장
    state ball;          // 초기 공 위치 저장 변수
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'R')
            {
                ball.rx = i, ball.ry = j; // 빨간 공 위치 저장
            }
            if (board[i][j] == 'B')
            {
                ball.bx = i, ball.by = j; // 파란 공 위치 저장
            }
        }
    queue<state> q; // 공 이동 위치 저장 큐 할당
    q.push(ball);
    visited[ball.rx][ball.ry][ball.bx][ball.by] = true; // 방문 체크
    while (!q.empty())
    {
        state cur = q.front(); // 현재 공 위치 할당
        q.pop();
        if (cur.cnt == 10)
            continue; // 10회 내에 도착하지 못한 경우 실패   
        for (int i = 0; i < 4; i++)
        {
            int rs, bs;  // 각각의 공 이동 칸 수 저장 변수
            bool rh, bh; // 각각의 공 인홀 체크 변수
            // 다음 빨간 공 위치 할당
            pair<int, int> rp = roll(board, cur.rx, cur.ry, i, rs, rh);
            int nrx = rp.first, nry = rp.second;
            // 다음 파란 공 위치 할당
            pair<int, int> bp = roll(board, cur.bx, cur.by, i, bs, bh);
            int nbx = bp.first, nby = bp.second;
            if (bh)
                continue; // 파란 공이 들어가면 실패
            if (rh)
            {
                cout << cur.cnt + 1; // 빨간 공이 들어가면 횟수 출력 후 코드 종료
                return 0;
            }
            if (nrx == nbx && nry == nby) // 공의 위치가 겹칠 때
            {
                // 파란 공이 먼저 도착했던 경우 빨간 공 한칸 뒤로 이동
                if (rs > bs)
                    nrx -= dx[i], nry -= dy[i];
                // 빨간 공이 먼저 도착했던 경우 파란 공 한칸 뒤로 이동
                else
                    nbx -= dx[i], nby -= dy[i];
            }
            if (!visited[nrx][nry][nbx][nby])
            {
                visited[nrx][nry][nbx][nby] = true;             // 방문 체크
                q.push(state{nrx, nry, nbx, nby, cur.cnt + 1}); // 이동 위치 큐에 할당
            }
        }
    }
    cout << -1; // 실패 시 -1 출력
    return 0;
}

pair<int, int> roll(const vector<string> &b, int x, int y, int dir, int &step, bool &hole)
{
    step = 0, hole = false; // 참조 변수 초기화
    while (1)
    {
        int nx = x + dx[dir], ny = y + dy[dir]; // 다음 이동 위치 할당
        if (b[nx][ny] == '#')
            break;      // 벽이랑 부딪히면 이동 중단
        x = nx, y = ny; // 다음 위치 이동
        step++;         // 이동 칸 수 카운팅
        if (b[nx][ny] == 'O')
        {
            hole = true; // 구멍으로 빠졌는 지 체크
            break;
        }
    }
    return {x, y};
}
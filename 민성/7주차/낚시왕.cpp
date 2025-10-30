#include <iostream>
#include <vector>

using namespace std;

struct Shark
{
    int r, c, s, d, z; // 상어 정보 저장 구조체 할당
    bool alive = true;
};

// 낚시 함수 정의
void fishing(vector<vector<int>> &b, vector<Shark> &sh, int r, int y);
// 상어 이동 함수 정의
void moving(vector<vector<int>> &b, vector<Shark> &sh, int r, int c);
int flip[5] = {0, 2, 1, 4, 3}; // 방향 전환 변수
int sm = 0;                    // 상어 크기 합 저장 변수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int R, C, r, c, m, s, d, z; // 상어 번호 저장 변수
    cin >> R >> C >> m;
    // 상어 위치 저장 배열
    vector<vector<int>> board(R + 1, vector<int>(C + 1, 0));
    // 상어 정보 저장 배열
    vector<Shark> shark(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> r >> c >> s >> d >> z;
        if (d == 1 || d == 2)
        {
            int cycle = (R > 1) ? 2 * (R - 1) : 0;
            if (cycle)
                s %= cycle; // 열 이동 거리 압축
        }
        else
        {
            int cycle = (C > 1) ? 2 * (C - 1) : 0;
            if (cycle)
                s %= cycle; // 행 이동 거리 압축
        }
        board[r][c] = i;            // 상어 위치 저장
        shark[i] = {r, c, s, d, z}; // 상어 정보 저장
    }
    for (int i = 1; i <= C; i++)
    {
        fishing(board, shark, R, i); // 먼저 낚시 후 상어 이동
        moving(board, shark, R, C);
    }
    cout << sm;
    return 0;
}

void fishing(vector<vector<int>> &b, vector<Shark> &sh, int R, int y)
{
    for (int i = 1; i <= R; i++)
    {
        int id = b[i][y];
        if (id)
        {
            sm += sh[id].z;       // 상어 크기 합산
            sh[id].alive = false; // 해당 상어 제외
            b[i][y] = 0;
            break;
        }
    }
}

void moving(vector<vector<int>> &b, vector<Shark> &sh, int R, int C)
{
    // 상어 이동 위치 저장 배열
    vector<vector<int>> nb(R + 1, vector<int>(C + 1, 0));
    for (int i = 1; i < sh.size(); i++)
    {
        if (!sh[i].alive)
            continue; // 제외된 상어 스킵
        // 현재 위치와 방향 할당
        int cr = sh[i].r, cc = sh[i].c, cd = sh[i].d;
        if (cd == 1 || cd == 2) // 세로 방향 전환
        {
            int len = R - 1; // 양 끝 사이 간격
            if (len)
            {
                int cycle = 2 * len; // 왕복 주기
                int idx = cr - 1;    // 나머지 연산을 위해 -1
                // 언폴드 방식 위치 설정
                int mv = (cd == 2 ? idx : cycle - idx);
                int m = (sh[i].s + mv) % cycle;
                if (m < 0)
                    m += cycle; // 음수면 양수로 전환
                if (m < len)
                {
                    cr = m + 1; // 정방향 구간
                    cd = 2;
                }
                else if (m == len)
                {
                    cr = len + 1; // 정방향 끝 도착
                    cd = 1;       // 방향 전환
                }
                else
                {
                    cr = (2 * len - m) + 1; // 역방향 구간
                    cd = 1;
                }
            }
        }
        else // 가로 방향 전환
        {
            int len = C - 1;
            if (len)
            {
                int cycle = 2 * len;
                int idx = cc - 1;
                int mv = (cd == 3 ? idx : cycle - idx);
                int m = (sh[i].s + mv) % cycle;
                if (m < 0)
                    m += cycle;
                if (m < len)
                {
                    cc = m + 1;
                    cd = 3;
                }
                else if (m == len)
                {
                    cc = len + 1;
                    cd = 4;
                }
                else
                {
                    cc = (2 * len - m) + 1;
                    cd = 4;
                }
            }
        }
        int check = nb[cr][cc];
        if (!check)
        {
            nb[cr][cc] = i; // 빈 공간이면 상어 이동
            sh[i].r = cr, sh[i].c = cc, sh[i].d = cd;
        }
        else if (sh[check].z < sh[i].z)
        {
            // 이동한 상어가 원래 있던 상어보다 크면 잡아먹고 이동
            sh[check].alive = false;
            nb[cr][cc] = i;
            sh[i].r = cr, sh[i].c = cc, sh[i].d = cd;
        }
        else
            sh[i].alive = false; // 원래 있던 상어보다 작으면 잡아먹힘
    }
    b.swap(nb); // 원본 보드에 적용
}
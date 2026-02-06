#include <iostream>
#include <vector>

using namespace std;

// 공 정보 저장 구조체 설정
struct ball
{
    int s;
    char c;
};

// 공 정보 저장 배열 할당
ball b[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 충돌 수 저장 변수
    int l, n, t, cnt = 0;
    cin >> l >> n >> t;
    // 공 정보 저장
    for (int i = 0; i < n; i++)
        cin >> b[i].s >> b[i].c;
    for (int i = 1; i <= t; i++)
    {
        // 이동 후 공 위치 저장 배열
        vector<int> p(l + 1, -1);
        for (int j = 0; j < n; j++)
        {
            // 방향 델타값 저장 변수
            int d;
            // 방향에 따른 위치 델타값 할당
            if (b[j].c == 'R')
                d = 1;
            else
                d = -1;
            // 위치 갱신
            b[j].s += d;
            // 위치 변수에 할당
            int pos = b[j].s;
            // 벽에 충돌한 경우
            if (pos == 0 || pos == l)
                b[j].c == 'R' ? b[j].c = 'C' : b[j].c = 'R';
            // 해당 위치에 공이 이미 존재하면 충돌 카운팅 및 방향 스위칭
            if (p[pos] != -1)
            {
                cnt++;
                b[p[pos]].c == 'R' ? b[p[pos]].c = 'C' : b[p[pos]].c = 'R';
                b[j].c == 'R' ? b[j].c = 'C' : b[j].c = 'R';
            }
            // 빈 공간이면 이동한 공 배치
            else
                p[pos] = j;
        }
    }
    cout << cnt;
    return 0;
}
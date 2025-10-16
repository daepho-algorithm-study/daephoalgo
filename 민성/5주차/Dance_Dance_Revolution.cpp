#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int force(int f, int b); // 힘 계산 함수 정의
vector<int> seq;         // 수열 저장 배열
int ddr[2][5][5];        // DDR 누적 결과 저장 배열
int INF = 500000;        // 초기화 변수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    while (1)
    {
        cin >> num;
        if (num == 0)
            break;
        seq.push_back(num);
    }
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            ddr[0][i][j] = INF; // 배열 초기화
            ddr[1][i][j] = INF;
        }
    ddr[0][0][0] = 0; // 초기값 할당
    for (int k = 0; k < seq.size(); k++)
    {
        int nxt = seq[k];
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
            {
                if (ddr[0][i][j] == INF)
                    continue; // 밟은 적 없는 공간은 제외
                // 최소 힘으로 움직인 값을 누적
                if (nxt != j)
                    ddr[1][nxt][j] = min(ddr[1][nxt][j], ddr[0][i][j] + force(i, nxt));
                if (nxt != i)
                    ddr[1][i][nxt] = min(ddr[1][i][nxt], ddr[0][i][j] + force(j, nxt));
            }
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
            {
                ddr[0][i][j] = ddr[1][i][j]; // 다음 누적을 위해 값 이동
                ddr[1][i][j] = INF;          // 배열 초기화
            }
    }
    int mn = INF; // 최소 힘 저장 변수
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (ddr[0][i][j] < mn)
                mn = ddr[0][i][j]; // 최소 힘 갱신
    cout << mn;
    return 0;
}

int force(int f, int b)
{
    if (f == b)
        return 1; // 제자리면 1의 힘 사용
    else if (f == 0)
        return 2; // 중앙에서 시작하면 2의 힘 사용
    else if (abs(f - b) == 1 || abs(f - b) == 3)
        return 3; // 인접한 지점 이동 시 3의 힘 사용
    else
        return 4; // 반대편 이동 시 4의 힘 사용
}
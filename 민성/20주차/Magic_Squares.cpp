#include <iostream>

using namespace std;

// 매직 스퀘어 저장 배열
int sq[5][5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    while (n--)
    {
        cin >> m;
        // 매직 스퀘어값 저장
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                cin >> sq[i][j];
        // 비교값 할당 변수
        int comp = 0;
        // 매직 스퀘어 체크 변수
        bool check = true;
        for (int i = 0; i < m; i++)
        {
            // 매직 스퀘어 조건 확인 후 스킵
            if (!check)
                break;
            // 가로 세로줄 합 할당 변수
            int x = 0, y = 0;
            // 가로 세로줄 한 줄 합 할당
            for (int j = 0; j < m; j++)
            {
                x += sq[i][j];
                y += sq[j][i];
            }
            // 초기 비교값이 없으면 할당
            if (comp == 0)
                comp = x;
            // 매직 스퀘어 조건 불충족 시 바로 체크
            if (comp != x || comp != y)
            {
                check = false;
                break;
            }
        }
        // 대각선 합 할당 변수
        int diag1 = 0, diag2 = 0;
        // 대각선 합 할당
        for (int i = 0; i < m; i++)
        {
            diag1 += sq[i][i];
            diag2 += sq[i][m - 1 - i];
        }
        // 매직 스퀘어 조건 체크
        if (comp != diag1 || comp != diag2)
            check = false;
        if (check)
            cout << "Magic square of size " << m << "\n";
        else
            cout << "Not a magic square" << "\n";
    }
    return 0;
}
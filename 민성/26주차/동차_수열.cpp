#include <iostream>

using namespace std;

// 보드 정보 저장 배열
int board[1000][1000];
// 같은 행 차이값 저장 배열
int dif[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (1)
    {
        cin >> n;
        // n이 0이 들어오면 반복 종료
        if (n == 0)
            break;
        // 보드 정보 저장
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> board[i][j];
        // 동차 확인 변수
        bool check = true;
        // 첫번째 행 초기값 할당
        int v = board[0][0];
        for (int i = 0; i < n; i++)
            dif[i] = board[0][i] - v;
        for (int i = 1; i < n; i++)
        {
            // 동차가 아니면 반복 종료
            if (!check)
                break;
            // 각 행의 첫번째 값 할당
            v = board[i][0];
            // 행의 차이값이 다르다면 동차 X
            for (int j = 0; j < n; j++)
                if (dif[j] != board[i][j] - v)
                {
                    check = false;
                    break;
                }
        }
        if (check)
            cout << "homogeneous";
        else
            cout << "not homogeneous";
        cout << "\n";
    }
    return 0;
}
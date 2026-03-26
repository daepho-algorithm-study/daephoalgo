#include <iostream>
#include <algorithm>

using namespace std;

// 행렬 정보 저장 배열
int board[251][251];
// 열 최대값, 최소값 저장 배열
int mxa[251][251], mna[251][251];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, b, k, x, y;
    cin >> n >> b >> k;
    // 행렬 정보 저장 및 최대값, 최소값 저장 배열 초기화
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
            mxa[i][j] = 0;
            mna[i][j] = 250;
        }
    // 열 범위 내 최대값, 최소값 탐색
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - b + 1; j++)
            for (int l = 0; l < b; l++)
            {
                mxa[i][j] = max(mxa[i][j], board[i][j + l]);
                mna[i][j] = min(mna[i][j], board[i][j + l]);
            }
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        // 최대값, 최소값 변수 할당
        int mx = mxa[x][y], mn = mna[x][y];
        // 범위 내 행 탐색 후 최대값, 최소값 갱신
        for (int l = 0; l < b; l++)
        {
            mx = max(mx, mxa[x + l][y]);
            mn = min(mn, mna[x + l][y]);
        }
        cout << mx - mn << "\n";
    }
    return 0;
}
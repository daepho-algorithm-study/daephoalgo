#include <iostream>

using namespace std;

// 거울 정보 저장 배열
string mirror[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n;
    // 거울 정보 저장
    for (int i = 0; i < n; i++)
        cin >> mirror[i];
    cin >> k;
    // 모습 그대로 출력
    if (k == 1)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << mirror[i][j];
            cout << "\n";
        }
    // 모습 좌우 반전
    else if (k == 2)
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j >= 0; j--)
                cout << mirror[i][j];
            cout << "\n";
        }
    // 모습 상하 반전
    else
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
                cout << mirror[i][j];
            cout << "\n";
        }
    return 0;
}
#include <iostream>

using namespace std;

// 수열 정보 저장 배열
int sq[12];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p;
    cin >> p;
    while (p--)
    {
        // 섬 개수 카운팅 변수
        int k, cnt = 0;
        cin >> k;
        // 수열 정보 저장
        for (int i = 0; i < 12; i++)
            cin >> sq[i];
        // 모든 부분 수열 탐색
        for (int l = 0; l < 10; l++)
        {
            for (int r = l + 2; r < 12; r++)
            {
                // 섬 충족 최소 조건(mn보다 섬의 모든 수가 커야함)
                int mn = max(sq[l], sq[r]);
                // 섬 조건 충족 체크 변수
                bool check = true;
                // 부분 수열 구성 수 중 조건 불만족인 수가 존재하면 체크
                for (int m = l + 1; m < r; m++)
                    if (sq[m] <= mn)
                        check = false;
                // 조건을 만족하면 섬 카운팅
                if (check)
                    cnt++;
            }
        }
        cout << k << " " << cnt << "\n";
    }
    return 0;
}
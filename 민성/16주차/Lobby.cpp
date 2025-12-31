#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    while (1)
    {
        cin >> n >> m >> k;
        // 입력값이 모두 0이면 반복문 종료
        if (!n && !m && !k)
            break;
        // 무소속 의원 수 저장
        int vt = n - m - k;
        // 법안 통과를 위해 필요한 투표 수
        int nd = max(0, n / 2 + 1 - m);
        // 투표 수를 충당 가능하면 투표 수 출력, 아니면 -1 출력
        if (nd <= vt)
            cout << nd << "\n";
        else
            cout << -1 << "\n";
    }
    return 0;
}
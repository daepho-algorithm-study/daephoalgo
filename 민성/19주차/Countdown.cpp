#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, k, num;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // 정답 저장 변수
        int ans = 0;
        cin >> n >> k;
        // 카운트다운 체크 변수
        int cd = k;
        while (n--)
        {
            cin >> num;
            // 카운트다운 성립 시 계속 탐색
            if (num == cd)
                cd--;
            // 카운트다운 실패 시 현재 값이 k면 k-1 탐색, 아니면 k 탐색
            else
                cd = (num == k ? k - 1 : k);
            // 카운트다운 완성 시 정답 카운팅
            if (cd == 0)
            {
                cd = k;
                ans++;
            }
        }
        cout << "Case #" << i << ": " << ans << "\n";
    }
    return 0;
}
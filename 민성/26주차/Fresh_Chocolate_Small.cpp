#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, p, num;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // 정답과 나머지 1, 2 개수 저장 변수
        int ans = 0, m1 = 0, m2 = 0;
        cin >> n >> p;
        // 나머지별로 각각의 변수에 합산
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            if (num % p == 0)
                ans++;
            else if (num % p == 1)
                m1++;
            else
                m2++;
        }
        // p가 2일 때와 3일 때를 구분하여 계산
        if (p == 2)
        {
            // 나머지 1인 2개의 그룹 중 하나는 새 것을 받음
            ans += m1 / 2;
            // 짝을 다 짓고 남은 그룹은 새 것을 받음
            if (m1 % 2 != 0)
                ans++;
        }
        else
        {
            // m1에 큰 수 저장
            if (m1 < m2)
                swap(m1, m2);
            // 나머지 1, 2 그룹을 짝지을 수 있을 만큼 짝 지음
            ans += m2;
            // 짝이 없는 그룹은 세 그룹씩 묶음 처리
            ans += (m1 - m2) / 3;
            // 짝을 다 짓고 남은 그룹 중 한 그룹은 새 것을 수령
            if ((m1 - m2) % 3 != 0)
                ans++;
        }
        cout << "Case #" << i << ": " << ans << "\n";
    }
    return 0;
}
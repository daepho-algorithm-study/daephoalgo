#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        // 수열 내 최댓값 저장 변수
        int mx = n;
        while (n != 1)
        {
            // 문제 조건대로 수열 생성
            if (n % 2 == 0)
                n /= 2;
            else
                n = n * 3 + 1;
            // 최댓값 갱신
            if (mx < n)
                mx = n;
        }
        cout << mx << "\n";
    }
    return 0;
}
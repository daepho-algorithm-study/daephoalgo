#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    // 세제곱 값 저장 배열
    long long mul[1111];
    // 세제곱 값 저장
    for (int i = 1; i < 1111; i++)
        mul[i] = 1LL * i * i * i;
    while (1)
    {
        // 최댓값 저장 변수
        int mx = 0;
        cin >> n;
        // 0이 들어오면 종료
        if (n == 0)
            return 0;
        // z^3 할당
        int z = mul[n];
        for (int i = 1; i < n; i++)
            for (int j = 1; j < n; j++)
            {
                // x^3 + y^3 값 저장
                int sm = mul[i] + mul[j];
                // 범위 초과 시 스킵
                if (sm >= z)
                    break;
                // 최댓값 갱신
                if (mx < sm)
                    mx = sm;
            }
        cout << z - mx << "\n";
    }
}
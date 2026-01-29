#include <iostream>
#include <string>

using namespace std;

// 행복한 소수 판별 배열(false가 행복한 소수)
bool happy[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 소수 판별(에라토스테네스의 체)
    happy[1] = true;
    for (int i = 2; i <= 100; i++)
        for (int j = i; i * j <= 10000; j++)
            happy[i * j] = true;
    for (int i = 2; i <= 10000; i++)
        // 소수 중에서 행복한 수 판별
        if (!happy[i])
        {
            // 중복 체크 배열
            bool dup[400] = {false};
            // 자리수 계산을 위해 변수형 변환
            string s = to_string(i);
            // 자리수 제곱합 저장 변수
            int sm = 0;
            // 자리수 제곱합 저장
            for (int k = 0; k < s.size(); k++)
                sm += (s[k] - '0') * (s[k] - '0');
            // 제곱합이 1이거나 중복 수가 나올때까지 반복
            while (sm != 1 && !dup[sm])
            {
                dup[sm] = true;
                s = to_string(sm);
                sm = 0;
                for (int k = 0; k < s.size(); k++)
                    sm += (s[k] - '0') * (s[k] - '0');
            }
            // 행복한 수가 아니면 제외
            if (sm != 1)
                happy[i] = true;
        }
    int p, n, m;
    cin >> p;
    while (p--)
    {
        cin >> n >> m;
        cout << n << " " << m << " ";
        if (happy[m])
            cout << "NO";
        else
            cout << "YES";
        cout << "\n";
    }
    return 0;
}
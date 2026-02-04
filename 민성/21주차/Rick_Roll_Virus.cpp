#include <iostream>
#include <string>

using namespace std;

// 감염 유무 체크 배열
bool virus[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;
    // 감염자 위치 변수와 확산 카운팅 변수 할당
    int idx = 0, cnt = 0;
    // 좌측에서 우측으로 감염 탐색
    while (idx < n)
    {
        // 감염자 위치 발견 시
        if (s[idx] == 'R')
        {
            // 좌측 감염 확산 체크
            for (int i = idx - k; i <= idx; i++)
                if (i >= 0)
                    virus[i] = true;
            // 감염 확산 확인
            while (cnt <= k)
            {
                // 확산 상태 사이에 감염자 발견 시 확산 초기화
                if (s[idx] == 'R')
                    cnt = 0;
                virus[idx++] = true;
                cnt++;
            }
        }
        idx++;
    }
    // 감염자 수 카운팅 변수 할당
    cnt = 0;
    // 감염자 수 카운팅
    for (int i = 0; i < n; i++)
        if (virus[i])
            cnt++;
    if (cnt <= m)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
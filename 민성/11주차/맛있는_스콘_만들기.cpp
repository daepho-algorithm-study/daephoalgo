#include <iostream>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

int taste(int m, int b, int k); // 스콘의 맛 계산 함수 정의
int b[200];                     // 최적의 온도 저장 배열
int dp[2][25001];               // t 시간에 따른 최댓값 저장 dp 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, c, d;
    cin >> n >> m >> c >> d;
    int rng = d / c; // 범위 인덱스 할당
    for (int i = 0; i < n; i++)
        cin >> b[i]; // 최적의 온도 저장
    for (int i = 1; i <= m; i++)
        dp[0][i] = taste(m, b[0], i); // 시각 0일 때 온도에 따른 스콘의 맛 저장
    for (int t = 1; t < n; t++)       // 시각 t마다 누적
    {
        for (int mod = 0; mod < c; mod++) // 온도 c로 나눴을 때 나머지별로 그룹화
        {
            // 나머지가 r인 온도들의 시작점 할당, 나머지가 0일 경우 온도 C부터 시작
            int s = (mod == 0) ? c : mod;
            int e = (m - s) / c; // 범위 내 끝 온도의 인덱스 할당
            int idx = 0;         // 덱에 집어 넣은 인덱스 위치 표시 변수
            deque<pair<int, int>> dq;
            for (int i = 0; i <= e; i++)
            {
                int l = max(0, i - rng); // 왼쪽 범위 인덱스 설정
                while (!dq.empty() && dq.front().first < l)
                    dq.pop_front();      // 범위 밖 인덱스 값 제외
                int r = min(e, i + rng); // 오른쪽 범위 인덱스 설정
                while (idx <= r)         // 범위 내 탐색
                {
                    int k = s + idx * c; // 탐색한 대상의 실제 온도 할당
                    // 해당 온도의 누적값보다 작은 대상 제외
                    while (!dq.empty() && dq.back().second < dp[0][k])
                        dq.pop_back();
                    dq.push_back({idx, dp[0][k]}); // 최대 누적값 갱신
                    idx++;                         // 다음 인덱스 탐색
                }
                // 현재 탐색하는 온도의 범위 내 가장 큰 스콘의 맛을 누적
                dp[1][s + i * c] = dq.front().second + taste(m, b[t], s + i * c);
            }
        }
        // 다음 탐색을 위해 누적한 값을 비교값 위치로 스위칭
        for (int i = 1; i <= m; i++)
            dp[0][i] = dp[1][i];
    }
    int mx = 0; // 최대 스콘의 맛 저장 변수
    for (int i = 1; i <= m; i++)
        mx = max(mx, dp[0][i]); // 최대값 갱신
    cout << mx;
    return 0;
}

int taste(int m, int b, int k)
{
    return m - abs(b - k); // 스콘의 맛 계산값 리턴
}
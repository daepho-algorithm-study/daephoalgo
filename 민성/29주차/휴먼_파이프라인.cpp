#include <iostream>
#include <algorithm>

using namespace std;

// 작업 속도 저장 배열
int v[200000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    // 가장 빠른 작업 속도 저장 변수 할당
    long long k, mx = 0;
    cin >> n >> k;
    // 작업 속도 저장
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // 작업 속도 오름차순 정렬
    sort(v, v + n);
    // 팀 나누는 구간을 오른쪽으로 한 칸씩 이동하면서 탐색
    for (int i = 0; i < n - 1; i++)
    {
        // 현재 팀 작업속도 합 할당
        long long cv = 1LL * v[0] * (i + 1) + 1LL * v[i + 1] * (n - i - 1);
        // 최대 속도 갱신
        if (mx < cv)
            mx = cv;
    }
    // 정답 저장 변수
    long long ans = k / mx;
    // 나머지 존재 시 올림
    if (k % mx != 0)
        ans++;
    cout << ans;
    return 0;
}
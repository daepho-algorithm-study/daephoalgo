#include <iostream>
#include <queue>

using namespace std;
int mn[100001];  // 이 위치 방문 최소 시간 저장 배열
int cnt[100001]; // 경우의 수 저장 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    queue<int> q;
    cin >> n >> k;
    for (int i = 0; i <= 100000; i++)
        mn[i] = -1; // 배열 초기화
    q.push(n);
    mn[n] = 0;
    cnt[n] = 1; // 초기값 갱신
    while (!q.empty())
    {
        int p = q.front(); // 현재 위치 할당
        q.pop();
        for (int np : {p - 1, p + 1, p * 2})
        {
            if (np < 0 || np > 100000)
                continue; // 범위 이탈 시 제외
            if (mn[np] != -1)
            {
                if (mn[np] == mn[p] + 1)
                    cnt[np] += cnt[p]; // 같은 시간으로 올 수 있는 경우의 수 합산
            }
            else
            {
                q.push(np);         // 다음 이동 위치 저장
                mn[np] = mn[p] + 1; // 처음 방문하는 위치는 시간과 경우의 수 갱신
                cnt[np] = cnt[p];
            }
        }
    }
    cout << mn[k] << "\n"
         << cnt[k];
    return 0;
}
#include <iostream>
#include <deque>

using namespace std;

// 원소 저장 덱
deque<int> dq;
// 뽑아낼 원소 저장 배열
int a[50];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    // 원소 체크
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        dq.push_back(i);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    // 탐색 원소 인덱스 할당 변수와 정답 저장 변수
    int idx = 0, ans = 0;
    while (idx < m)
    {
        // 덱 크기 할당
        int dqs = dq.size();
        for (int i = 0; i < dqs; i++)
            // 대상 원소 탐색
            if (a[idx] == dq[i])
            {
                // 왼쪽이 더 가까우면 오른쪽으로 이동
                if (i <= dqs / 2)
                {
                    ans += i;
                    for (int j = 0; j < i; j++)
                    {
                        dq.push_back(dq.front());
                        dq.pop_front();
                    }
                    dq.pop_front();
                }
                // 오른쪽이 더 가까우면 왼쪽으로 이동
                else
                {
                    ans += dqs - i;
                    for (int j = 0; j < dqs - i; j++)
                    {
                        dq.push_front(dq.back());
                        dq.pop_back();
                    }
                    dq.pop_front();
                }
                // 다음 대상 할당
                idx++;
                break;
            }
    }
    cout << ans;
    return 0;
}
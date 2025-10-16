#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long INF = 5000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long a, b, c, mn = INF;
    cin >> n;
    vector<long long> liq(n); // 용액 특성값 저장 배열 할당
    for (int i = 0; i < n; i++)
        cin >> liq[i];            // 용액 특성값 저장
    sort(liq.begin(), liq.end()); // 특성값 오름차순 정렬
    for (int i = 0; i < n; i++)
    {
        int s = i + 1, e = n - 1; // 투 포인터 변수
        while (s < e)
        {
            long long sm = liq[i] + liq[s] + liq[e]; // 세 용액 특성값 합 저장
            if (abs(sm) < mn)
            {
                a = i, b = s, c = e; // 해당 용액 번호 저장
                mn = abs(sm);
            }
            if (sm < 0)
                s++; // 합이 0보다 작으면 작은 수 쪽을 이동
            else if (sm > 0)
                e--; // 합이 0보다 크면 큰 수 쪽을 이동
            else
                break; // 합이 0이면 반복문 종료
        }
    }
    cout << liq[a] << " " << liq[b] << " " << liq[c];
    return 0;
}
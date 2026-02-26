#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

// 물고기 킬로그램 수 저장 배열
int kg[100000];
// 판매원의 구매 생선 수와 킬로그램당 가격 저장 배열
pair<int, int> fm[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    // 물고기 무게 저장
    for (int i = 0; i < n; i++)
        cin >> kg[i];
    // 판매원 정보 저장
    for (int i = 0; i < m; i++)
        cin >> fm[i].second >> fm[i].first;
    // 물고기와 판매원 정보 내림차순 정렬
    sort(kg, kg + n, greater<int>());
    sort(fm, fm + m, greater<pair<int, int>>());
    // 현재 판매중인 물고기 위치와 정답 저장 변수
    int idx = 0;
    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        // 생선 금액과 개수 할당
        int p = fm[i].first, k = fm[i].second;
        // 모든 물고기가 다 팔릴 때까지 판매
        for (int j = 0; j < k && idx < n; j++, idx++)
            ans += 1LL * p * kg[idx];
    }
    cout << ans;
    return 0;
}
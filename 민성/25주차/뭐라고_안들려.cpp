#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    // 정답 합산 변수 할당
    long long x, y, k, ans = 0;
    unordered_map<long long, int> h;
    cin >> n >> k;
    // 각 점을 통과하는 k 기울기의 직선 해시에 저장
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        long long temp = y - x * k;
        h[temp]++;
    }
    // 두 점 이상 지나는 직선의 경우의 체크
    for (auto &v : h)
        ans += 1LL * v.second * (v.second - 1);
    cout << ans;
    return 0;
}
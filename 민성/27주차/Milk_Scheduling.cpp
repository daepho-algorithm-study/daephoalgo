#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

// 우유량과 기한 저장 배열
pair<int, int> cow[10000];
// 현재 짤 우유량 저장 우선순위 큐
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 정답 저장 변수 할당
    int n, ans = 0;
    cin >> n;
    // 우유량과 기한 저장(기한이 앞에 오게 저장)
    for (int i = 0; i < n; i++)
        cin >> cow[i].second >> cow[i].first;
    // 기한 오름차순으로 정렬
    sort(cow, cow + n);
    for (int i = 0; i < n; i++)
    {
        // 기한과 우유량 할당
        int d = cow[i].first, g = cow[i].second;
        // 우유량 합산
        pq.push(g);
        ans += g;
        // 기한 초과 시 가장 작은 우유량 하나 제거
        if (pq.size() > d)
        {
            ans -= pq.top();
            pq.pop();
        }
    }
    cout << ans;
    return 0;
}
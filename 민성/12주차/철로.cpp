#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, h, o, d, cnt = 0, mx = 0; // 현재 포함 수와 최대 포함 수 저장 변수
    pair<int, int> p[100000];        // 집 사무실 위치 저장 배열
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h >> o;
        if (h < o)
            swap(h, o);
        p[i] = {h, o}; // 오른쪽, 왼쪽 순서로 저장
    }
    cin >> d;
    sort(p, p + n); // 오른쪽 지점을 기준으로 오름차순 정렬
                    // 스위핑을 위한 오름차순 우선순위 큐
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(p[i].second); // 왼쪽 지점 우선순위 큐에 삽입
        cnt++;                // 포함 수 1 증가
        while (!pq.empty() && p[i].first - d > pq.top())
        {
            pq.pop(); // 왼쪽 시작점이 철로 범위 밖인 경우 제외
            cnt--;    // 제외한 만큼 포함 수 감소
        }
        if (cnt > mx)
            mx = cnt; // 최대값 갱신
    }
    cout << mx;
    return 0;
}
#include <iostream>
#include <deque>
#include <utility>
#include <algorithm>

using namespace std;

int bridge[100000];          // 징검다리 정수 저장 배열
long long mx = -1000000000; // 최댓값 저장 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++)
        cin >> bridge[i];           // 징검다리 정수 저장
    deque<pair<long long, int>> dq; // 누적값과 인덱스 저장 덱
    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && dq.front().second < i - d)
            dq.pop_front(); // 범위 밖 제외
        // 현재 위치까지 최대 누적값 계산
        long long best = 0;
        if (!dq.empty() && dq.front().first > 0)
            best = dq.front().first;      // 덱의 값이 0보다 클 때만 사용
        long long cur = bridge[i] + best; // 현재 최대 누적값 계산
        while (!dq.empty() && dq.back().first <= cur)
            dq.pop_back();      // 현재 누적값보다 작은 값 모두 제외
        dq.push_back({cur, i}); // 현재 누적값 덱에 삽입
        mx = max(mx, cur);    // 최댓값 갱신
    }
    cout << mx;
    return 0;
}
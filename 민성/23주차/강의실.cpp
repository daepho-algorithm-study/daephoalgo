#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

// 강의 시간 저장 배열
pair<int, int> lec[100000];
// 끝나는 시간을 저장할 우선순위 큐 할당
priority_queue<int, vector<int>, greater<int>> e;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 정답 저장 변수
    int n, num, ans = 0;
    cin >> n;
    // 강의 시간 저장
    for (int i = 0; i < n; i++)
        cin >> num >> lec[i].first >> lec[i].second;
    // 시작 시간 순으로 오름차순 정렬
    sort(lec, lec + n);
    // 첫번째 강의 시간 할당
    ans++;
    e.push(lec[0].second);
    for (int i = 1; i < n; i++)
    {
        // 강의실을 그대로 사용 가능하면 종료 시간만 갱신
        if (e.top() <= lec[i].first)
            e.pop();
        // 사용 불가하면 강의실 하나 추가
        else
            ans++;
        e.push(lec[i].second);
    }
    cout << ans;
    return 0;
}
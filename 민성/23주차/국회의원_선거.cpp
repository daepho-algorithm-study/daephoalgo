#include <iostream>
#include <queue>

using namespace std;

// 투표 수 저장 우선순위 큐
priority_queue<int> vote;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 다솜이 투표 수와 정답 저장 변수
    int n, num, dasom, ans = 0;
    // 투표 수 저장
    cin >> n >> dasom;
    // 다솜이 혼자면 0 출력
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    // 나머지 투표 수 우선순위 큐에 삽입
    for (int i = 1; i < n; i++)
    {
        cin >> num;
        vote.push(num);
    }
    // 우선순위 큐 내 최고 투표 수 추출
    int mx = vote.top();
    vote.pop();
    // 다솜이의 투표 수가 제일 많을 때까지 반복
    while (mx >= dasom)
    {
        ans++;
        dasom++;
        vote.push(mx - 1);
        mx = vote.top();
        vote.pop();
    }
    cout << ans;
    return 0;
}
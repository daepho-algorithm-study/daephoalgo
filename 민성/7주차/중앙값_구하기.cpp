#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, m, num;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        priority_queue<int> u;                            // 작은 수 절반 저장 큐
        priority_queue<int, vector<int>, greater<int>> d; // 큰 수 절반 저장 큐
        vector<int> mid;                                  // 중앙값 저장 배열
        cin >> m >> num;
        u.push(num);        // 첫 수 큐에 삽입
        mid.push_back(num); // 첫 번째 중앙값 저장
        for (int j = 0; j < m - 1; j++)
        {
            int temp = u.top(); // 비교 대상
            cin >> num;
            if (temp >= num)
                u.push(num); // 중간 수보다 작으면 작은 수 큐 저장
            else
                d.push(num); // 중간 수보다 크면 큰 수 큐 저장
            if (u.size() > d.size() + 1)
            {
                // 작은 수 저장 큐가 큰 수 큐의 크기보다 1 크거나 같게 유지
                d.push(temp);
                u.pop();
            }
            else if (u.size() < d.size())
            {
                u.push(d.top());
                d.pop();
            }
            if (j % 2 == 1)
                mid.push_back(u.top()); // 홀수번째에 중앙값 저장
        }
        int cnt = mid.size(); // 중앙값 개수 저장 변수
        cout << cnt << "\n";
        for (int j = 0; j < cnt; j++)
        {
            if (j && j % 10 == 0)
                cout << "\n"; // 한 줄에 10개씩 출력
            cout << mid[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
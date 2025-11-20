#include <iostream>
#include <deque>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l, A;
    cin >> n >> l;
    // 최솟값과 번호 저장 덱
    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++)
    {
        cin >> A;
        while (!dq.empty() && dq.back().first > A)
            dq.pop_back(); // A보다 큰 수는 제외
        dq.push_back({A, i});
        while (!dq.empty() && dq.front().second <= i - l)
            dq.pop_front();       // 범위 밖 번호는 제외
        int a = dq.front().first; // 최솟값 할당
        cout << a << " ";
    }
    return 0;
}
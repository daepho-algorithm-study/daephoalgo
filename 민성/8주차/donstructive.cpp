#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    deque<int> d; // 순열 저장 덱
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        // 중심부가 가장 큰 수가 되면서 가장자리가 작은 수가 되게 덱 구성
        if (i % 2 == 0)
            d.push_front(i);
        else
            d.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << d.front() << " "; // 덱 앞에서부터 하나씩 출력
        d.pop_front();
    }
    return 0;
}
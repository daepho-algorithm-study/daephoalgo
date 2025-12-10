#include <iostream>
#include <queue>
using namespace std;

int n, k;
queue<int> q;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;   // n: 사람 수, k: 제거할 순번

    // 1부터 n까지 큐에 삽입
    for (int i = 1; i <= n; i++)
        q.push(i);

    cout << "<";

    int cnt = 1; // 현재 몇 번째 사람인지 카운트할 변수

    // 큐가 빌 때까지 반복
    while (!q.empty())
    {
        if (cnt == k) {          // k번째 사람이 되면 제거할 차례
            cout << q.front();   // 제거될 사람 출력
            q.pop();             // 큐에서 제거

            if (!q.empty())      // 마지막 사람이 아니라면 콤마 출력
                cout << ", ";

            cnt = 1;             // 다시 카운트를 1로 초기화
        }
        else {
            // 아직 k번째가 아니면 맨 앞 사람을 맨 뒤로 보냄
            q.push(q.front());
            q.pop();

            cnt++;               // 카운터 증가
        }
    }

    cout << ">"; // 출력 형식 마무리
    return 0;
}

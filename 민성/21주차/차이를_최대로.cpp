#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// 배열 A의 값과 순서 저장 배열
int A[8], sq[8];
// 방문 체크 배열
bool visited[8];
// 백트래킹 함수 정의
void bt(int k);
// 최댓값 저장 변수 할당
int n, mx = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    // 배열 A 정보 저장
    for (int i = 0; i < n; i++)
        cin >> A[i];
    // 모든 배열 순서 조합 탐색
    bt(0);
    cout << mx;
    return 0;
}

void bt(int k)
{
    if (k == n)
    {
        int sm = 0;
        // 현재 수열 위치대로 계산 후 최댓값 갱신
        for (int i = 0; i < n - 1; i++)
            sm += abs(A[sq[i]] - A[sq[i + 1]]);
        mx = max(mx, sm);
        return;
    }
    // 배열 순서를 스위칭
    for (int i = 0; i < n; i++)
        if (!visited[i])
        {
            visited[i] = true;
            sq[k] = i;
            bt(k + 1);
            visited[i] = false;
        }
}
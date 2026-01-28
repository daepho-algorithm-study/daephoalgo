#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

// 세종이가 받아야 하는 최소 금액과 날짜 저장 배열
pair<int, int> A[200000];
// 자루에 담은 금액 저장 배열
int B[200000];
// 출력 순서 저장 배열
int ans[200000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    // 최소 금액과 날짜 저장
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].first;
        A[i].second = i;
    }
    // 자루에 담은 금액 저장
    for (int i = 0; i < n; i++)
        cin >> B[i];
    // 오름차순 정렬
    sort(A, A + n);
    sort(B, B + n);
    // 불가능한 경우 확인
    for (int i = n - 1; i >= 0; i--)
        if (A[i].first > B[i])
        {
            cout << -1;
            return 0;
        }
    // 최소 금액 날짜에 해당 금액 할당
    for (int i = 0; i < n; i++)
        ans[A[i].second] = B[i];
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}
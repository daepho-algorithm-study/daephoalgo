#include <iostream>
#include <algorithm>
#include <utility>
#include <unordered_map>

using namespace std;

// 배열 A 저장 공간
int A[100000];
// 정렬된 A값 저장 배열
int comp[100000];
// 위치 저장 해시
unordered_map<int, int> pos;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    // 배열 A값과 위치 저장
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        comp[i] = A[i];
        pos[A[i]] = i;
    }
    // QuickSort 정렬로 시간 복잡도 최적화
    sort(comp, comp + n);
    // k번 정렬 후 확인
    int p = n - 1;
    while (k && p)
    {
        // 정렬되지 않았을 때 교환
        if (A[p] != comp[p])
        {
            // 교환 대상 값과 위치 할당
            int mx = comp[p], sw = A[p], q = pos[mx];
            swap(A[p], A[q]);
            pos[mx] = p;
            pos[sw] = q;
            k--;
        }
        // 다음 대상 탐색
        p--;
    }
    // k번 교환하지 못했을 시 -1 출력
    if (k)
        cout << -1;
    else
        for (int i = 0; i < n; i++)
            cout << A[i] << " ";
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

// 수열 저장 배열
int A[1000000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    // 수열 저장
    for (int i = 0; i < n; i++)
        cin >> A[i];
    // Quick Sort 정렬
    sort(A, A + n);
    // 정렬된 수열 출력
    for (int i = 0; i < n; i++)
        cout << A[i] << "\n";
    return 0;
}
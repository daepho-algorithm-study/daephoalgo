#include <iostream>
#include <algorithm>

using namespace std;

// 추의 밀도 저장 배열
int d[200000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 물질 개수 카운팅 변수
    int n, e, cnt = 1;
    cin >> n >> e;
    // 추의 밀도 저장
    for (int i = 0; i < n; i++)
        cin >> d[i];
    // 밀도 오름차순 정렬
    sort(d, d + n);
    // 오차 범위 이상 차이날 때를 카운팅
    for (int i = 0; i < n - 1; i++)
        if (d[i + 1] - d[i] >= e)
            cnt++;
    cout << cnt;
    return 0;
}
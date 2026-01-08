#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 수상 못한 학생 수 저장 변수
    int n, std = 0;
    // 참가자 해결 문제 수와 패널티 저장 배열
    pair<int, int> p[66];
    cin >> n;
    // 해결 문제 수와 패널티 저장
    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    // 내림차순 정렬
    sort(p, p + n, greater<pair<int, int>>());
    // 5등과 문제 수가 같은 학생 존재 시 카운팅
    for (int i = 5; i < n; i++)
    {
        if (p[i].first == p[4].first)
            std++;
        else
            break;
    }
    cout << std;
    return 0;
}
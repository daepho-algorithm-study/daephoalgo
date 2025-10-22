#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

// 외적 방향 계산 함수
int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3);
ll x[4], y[4]; // x, y 좌표 저장 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 4; i++)
        cin >> x[i] >> y[i]; // x, y 좌표 저장
    // 각 선분의 외적 방향 할당
    int s1 = ccw(x[0], y[0], x[1], y[1], x[2], y[2]),
        s2 = ccw(x[0], y[0], x[1], y[1], x[3], y[3]),
        s3 = ccw(x[2], y[2], x[3], y[3], x[0], y[0]),
        s4 = ccw(x[2], y[2], x[3], y[3], x[1], y[1]);
    if (s1 * s2 <= 0 && s3 * s4 <= 0)
    {
        if (s1 * s2 == 0 && s3 * s4 == 0)
        {
            // 점 위치 비교를 위한 할당
            pair<ll, ll> p1 = {x[0], y[0]},
                         p2 = {x[1], y[1]},
                         p3 = {x[2], y[2]},
                         p4 = {x[3], y[3]};
            if (p1 > p2)
                swap(p1, p2);
            if (p3 > p4)
                swap(p3, p4);
            if (p3 <= p2 && p1 <= p4)
                cout << 1; // 일직선으로 포개져 있으면 1 출력
            else
                cout << 0; // 일직선으로 떨어진 경우 0 출력
        }
        else
            cout << 1; // 일직선이 아닌 교차이면 1 출력
    }
    else
        cout << 0; // 교차점이 없으면 0 출력
    return 0;
}

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll s = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
    if (s > 0)
        return 1;
    else if (s < 0)
        return -1;
    else
        return 0;
}
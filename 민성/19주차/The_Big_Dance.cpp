#include <iostream>

using namespace std;

// 분할 정복 함수 정의
int bs(int s, int e);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << bs(1, n);
    return 0;
}

int bs(int s, int e)
{
    // 두 소가 정해지면 소 번호 곱 합산
    if (s + 1 == e)
        return s * e;
    // 소가 혼자 남으면 합산 X
    if (s == e)
        return 0;
    // 중간 지점 분할
    int m = (s + e) / 2;
    // 좌우 계산값 합산
    return bs(s, m) + bs(m + 1, e);
}
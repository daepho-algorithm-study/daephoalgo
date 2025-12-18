#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 에러 개수 저장 변수
    int n, cnt = 0;
    // 평균값 저장 변수
    double avg = 0;
    // 온도 저장 배열
    double temp[1000];
    cin >> n;
    // 온도 저장 및 합산
    for (int i = 0; i < n; i++)
    {
        cin >> temp[i];
        avg += temp[i];
    }
    // 평균값 계산
    avg /= n;
    // 평균과 10보다 더 크게 차이나면 에러
    for (int i = 0; i < n; i++)
        if (abs(temp[i] - avg) > 10.0)
            cnt++;
    cout << cnt;
    return 0;
}
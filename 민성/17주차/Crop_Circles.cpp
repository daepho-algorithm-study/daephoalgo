#include <iostream>
#include <cmath>

using namespace std;

// 소 영역 정보 저장 구조체 설정
struct cow
{
    int x, y, r;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    // 소 영역 정보 저장 배열
    cow f[400];
    // 겹침 영역 카운팅 배열
    int overlap[400] = {0};
    cin >> n;
    // 소 영역 정보 저장
    for (int i = 0; i < n; i++)
        cin >> f[i].x >> f[i].y >> f[i].r;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            // x축과 y축 기준 거리 차이 할당
            int dx = abs(f[i].x - f[j].x), dy = abs(f[i].y - f[j].y);
            // 원의 중심 간의 거리 계산(피타고라스)
            double d = sqrt(pow(dx, 2) + pow(dy, 2));
            // 원의 반지름 합보다 거리가 가까우면 겹침
            if (d < f[i].r + f[j].r)
            {
                overlap[i]++;
                overlap[j]++;
            }
        }
    for (int i = 0; i < n; i++)
        cout << overlap[i] << "\n";
    return 0;
}
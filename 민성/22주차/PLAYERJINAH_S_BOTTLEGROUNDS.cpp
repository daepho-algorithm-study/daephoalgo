#include <iostream>

using namespace std;

// 위치 할당 구조체 설정
struct point
{
    int x, y;
};

// 직선 판별 함수 정의
bool isline(point p1, point p2, point p3);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    point p1, p2, p3;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    if (isline(p1, p2, p3))
        cout << "WHERE IS MY CHICKEN?";
    else
        cout << "WINNER WINNER CHICKEN DINNER!";
    return 0;
}

bool isline(point p1, point p2, point p3)
{
    // ccw 계산값 할당
    int ccw = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);
    // 일직선일 때만 true 반환
    if (ccw == 0)
        return true;
    return false;
}
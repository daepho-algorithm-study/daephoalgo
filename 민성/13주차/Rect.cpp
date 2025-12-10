#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 직사각형 구조체 설정
struct rect
{
    int x, y, x1, y1, x2, y2;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 비교 불가 직사각형 쌍의 개수 저장 변수
    int n, cnt = 0;
    cin >> n;
    // 직사각형 정보 저장 배열
    vector<rect> rc(n);
    // 직사각형 정보 저장
    for (auto &r : rc)
        cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
    // 직사각형의 x축 길이와 y축 길이 저장
    for (auto &r : rc)
    {
        r.x = abs(r.x1 - r.x2);
        r.y = abs(r.y1 - r.y2);
        // x 변수에 짧은 쪽 변의 길이 저장
        if (r.x > r.y)
            swap(r.x, r.y);
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            // 비교 가능한 경우면 스킵
            if (rc[i].x <= rc[j].x && rc[i].y <= rc[j].y)
                continue;
            else if (rc[i].x >= rc[j].x && rc[i].y >= rc[j].y)
                continue;
            // 비교 불가 직사각형 쌍 카운팅
            cnt++;
        }
    cout << cnt;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

// 변의 길이 제곱 계산 함수 정의
long long len(pair<int, int> p1, pair<int, int> p2);
// 네 점 좌표 저장 배열
pair<int, int> sq[4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        // 네 점 좌표 저장
        for (int i = 0; i < 4; i++)
            cin >> sq[i].first >> sq[i].second;
        // 정렬 후 3번째, 4번째 좌표 스위칭
        sort(sq, sq + 4);
        swap(sq[2], sq[3]);
        // 정사각형 체크 변수
        bool check = true;
        // 한변 길이 할당
        long long l = len(sq[0], sq[3]);
        // 네 변 길이가 모두 같은 지 확인
        for (int i = 0; i < 3; i++)
            if (l != len(sq[i], sq[i + 1]))
            {
                check = false;
                break;
            }
        // 대각선의 길이가 같은 지 확인
        if (check && len(sq[0], sq[2]) != len(sq[1], sq[3]))
            check = false;
        if (check)
            cout << 1;
        else
            cout << 0;
        cout << "\n";
    }
    return 0;
}

long long len(pair<int, int> p1, pair<int, int> p2)
{
    // x, y 길이 차 할당
    long long x = p1.first - p2.first, y = p1.second - p2.second;
    // 피타고라스 방정식 이용
    return x * x + y * y;
}
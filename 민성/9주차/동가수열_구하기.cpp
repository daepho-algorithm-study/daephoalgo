#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int half = n / 2, num = half; // 증감 변수와 스타트 변수
    bool pm = true;               // 증감 판별 변수
    while (n--)
    {
        if (num == 0)
            num = half * 2 + 1; // 홀 수 크기 수열 마지막은 N 출력
        cout << num << " ";
        if (pm)
            num += half; // true일 때는 증가
        else
            num -= half + 1; // false일 때는 감소
        pm = !pm;            // pm 스위칭
    }
    return 0;
}
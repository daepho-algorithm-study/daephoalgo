#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 평점 환산 함수 정의
double calc(double g, int k, int c, double grade);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 수강 학점 총합 저장 변수
    int n, k, c = 0;
    string s;
    // 수강 평점 총합 저장 변수
    double x, g = 0;
    cin >> n >> x;
    for (int i = 0; i < n - 1; i++)
    {
        // 평점 할당 변수
        double v = 0;
        cin >> k >> s;
        // 학점 합산
        c += k;
        // 평점 계산
        if (s[0] == 'A')
            v = 4;
        else if (s[0] == 'B')
            v = 3;
        else if (s[0] == 'C')
            v = 2;
        else if (s[0] == 'D')
            v = 1;
        if (s.size() == 2 && s[1] == '+')
            v += 0.5;
        // 평점 * 학점 합산
        g += k * v;
    }
    cin >> k;
    // 필요 평점에 따른 결과 출력
    if (calc(g, k, c, 0.0) > x)
        cout << "F";
    else if (calc(g, k, c, 1.0) > x)
        cout << "D0";
    else if (calc(g, k, c, 1.5) > x)
        cout << "D+";
    else if (calc(g, k, c, 2.0) > x)
        cout << "C0";
    else if (calc(g, k, c, 2.5) > x)
        cout << "C+";
    else if (calc(g, k, c, 3.0) > x)
        cout << "B0";
    else if (calc(g, k, c, 3.5) > x)
        cout << "B+";
    else if (calc(g, k, c, 4.0) > x)
        cout << "A0";
    else if (calc(g, k, c, 4.5) > x)
        cout << "A+";
    else
        cout << "impossible";
    return 0;
}

double calc(double g, int k, int c, double grade)
{
    return floor(100 * (g + k * grade) / (c + k)) / 100;
}
#include <iostream>
#include <array>

using namespace std;
using ll = long long;
using Mat = array<array<ll, 8>, 8>;

Mat mul(const Mat &mtx, int x); // 행렬 제곱 함수
// 각 캠퍼스 이동 경우의 수 저장 배열
Mat campus = {{{0, 1, 1, 0, 0, 0, 0, 0},
               {1, 0, 1, 1, 0, 0, 0, 0},
               {1, 1, 0, 1, 1, 0, 0, 0},
               {0, 1, 1, 0, 1, 1, 0, 0},
               {0, 0, 1, 1, 0, 1, 0, 1},
               {0, 0, 0, 1, 1, 0, 1, 0},
               {0, 0, 0, 0, 0, 1, 0, 1},
               {0, 0, 0, 0, 1, 0, 1, 0}}};
ll MOD = 1000000007; // 나눔수 설정

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d;
    cin >> d;
    Mat sq  = mul(campus, d);
    cout << sq[0][0]; // 정보대의 값 출력
    return 0;
}

Mat mul(const Mat &mtx, int x)
{
    if (x == 1)
        return mtx;
    Mat half = mul(mtx, x / 2); // 분할 정복을 위해 x값 반으로 분할
    Mat temp{};                 // 배열 초기화
    for (int i = 0; i < 8; i++)
        for (int k = 0; k < 8; k++)
            if (half[i][k])
                for (int j = 0; j < 8; j++)
                {
                    temp[i][j] += half[i][k] * half[k][j];
                    temp[i][j] %= MOD; // 행렬 제곱 계산
                }
    if (x % 2 == 0)
        return temp; // x가 짝수면 리턴
    Mat res{};
    for (int i = 0; i < 8; i++)
        for (int k = 0; k < 8; k++)
            if (temp[i][k])
                for (int j = 0; j < 8; j++)
                {
                    res[i][j] += temp[i][k] * mtx[k][j];
                    res[i][j] %= MOD; // 행렬 제곱 계산
                }
    return res; // x가 홀수면 초기 배열 한번 더 곱셈
}
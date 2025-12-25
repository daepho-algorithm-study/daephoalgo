#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    for (int k = 1;; k++)
    {
        cin >> n;
        // 입력값이 0이 들어오면 종료
        if (!n)
            break;
        // 블럭 높이 저장 배열
        int brick[50];
        // 블럭 높이 합산 저장 변수
        int sm = 0;
        // 이동 수 카운팅 변수
        int cnt = 0;
        // 블럭 높이 저장 및 합산
        for (int i = 0; i < n; i++)
        {
            cin >> brick[i];
            sm += brick[i];
        }
        // 높이 평균 계산
        sm /= n;
        // 평균 높이와의 차이 합산
        for (int i = 0; i < n; i++)
            cnt += abs(brick[i] - sm);
        cout << "Set #" << k << "\n";
        cout << "The minimum number of moves is " << cnt / 2 << ".\n\n";
    }
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int score[100000][3]; // 점수를 저장할 배열
int mn[2][3];         // 최대 누적 점수를 저장할 배열
int mx[2][3];         // 최소 누적 점수를 저장할 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> score[i][0] >> score[i][1] >> score[i][2];
    for (int i = 0; i < 3; i++)
    {
        mn[0][i] = score[0][i]; // 초기값 갱신
        mx[0][i] = score[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        // 각 자리의 최댓값 저장
        mx[1][0] = score[i][0] + max(mx[0][0], mx[0][1]);
        mx[1][1] = score[i][1] + max({mx[0][0], mx[0][1], mx[0][2]});
        mx[1][2] = score[i][2] + max(mx[0][1], mx[0][2]);
        // 각 자리의 최솟값 저장
        mn[1][0] = score[i][0] + min(mn[0][0], mn[0][1]);
        mn[1][1] = score[i][1] + min({mn[0][0], mn[0][1], mn[0][2]});
        mn[1][2] = score[i][2] + min(mn[0][1], mn[0][2]);
        // 다음 탐색 준비를 위해 비교 공간에 값 저장
        for (int i = 0; i < 3; i++)
        {
            mn[0][i] = mn[1][i];
            mx[0][i] = mx[1][i];
        }
    }
    int Mx = max({mx[0][0], mx[0][1], mx[0][2]}); // 최대값 저장
    int Mn = min({mn[0][0], mn[0][1], mn[0][2]}); // 최소값 저장
    cout << Mx << " " << Mn;
    return 0;
}
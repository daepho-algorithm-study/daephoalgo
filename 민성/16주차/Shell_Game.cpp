#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 최대 점수 저장 변수
    int n, mx = 0;
    // 셔플 정보 저장 배열
    int shf[100][3];
    cin >> n;
    // 셔플 정보 저장
    for (int i = 0; i < n; i++)
        cin >> shf[i][0] >> shf[i][1] >> shf[i][2];
    for (int k = 1; k <= 3; k++)
    {
        // 점수 저장 변수
        int score = 0;
        // 구슬 유무 정보 저장 배열
        bool shell[4] = {false};
        // 각 자리의 조개에 구슬이 있다고 가정
        shell[k] = true;
        // N번 셔플과 추측 검증 후 정답 시 점수 득점
        for (int i = 0; i < n; i++)
        {
            swap(shell[shf[i][0]], shell[shf[i][1]]);
            if (shell[shf[i][2]])
                score++;
        }
        // 최대 점수 갱신
        if (score > mx)
            mx = score;
    }
    cout << mx;
    return 0;
}
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> signals)
{
    int answer = -1;
    // 탐색 범위 변수와 배열 크기 할당
    int rng = 1, ss = signals.size();
    // 노란불 주기, 위치 범위 정보 저장 배열
    vector<vector<int>> yellow(ss);
    // 최대 범위 할당(20^5)
    for (int i = 0; i < ss; i++)
        rng *= 20;
    // 노란불 정보 저장
    for (int i = 0; i < ss; i++)
    {
        // 주기 변수 할당
        int t = signals[i][0] + signals[i][1] + signals[i][2];
        // 위치 변수 할당
        int p = signals[i][0] + 1;
        // 범위 변수 할당
        int r = signals[i][1] - 1;
        // 주기, 위치, 범위 순으로 정보 저장
        yellow[i].push_back(t);
        yellow[i].push_back(p);
        yellow[i].push_back(r);
    }
    for (int i = 1; i <= rng; i++)
    {
        // 노란불 체크 변수 할당
        bool check = true;
        for (int j = 0; j < ss; j++)
        {
            // 주기로 나눈 나머지 할당
            int idx = i % yellow[j][0];
            // 노란불 범위 밖이면 체크 후 반복 종료
            if (idx < yellow[j][1] || idx > yellow[j][1] + yellow[j][2])
            {
                check = false;
                break;
            }
        }
        // 모두 노란불이 켜졌으면 정답 저장 후 반복 종료
        if (check)
        {
            answer = i;
            break;
        }
    }
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 각 스테이지 힌트권 보유 수 저장 배열
int cnt[16];
// 스테이지 수와 힌트권 수 저장 변수 할당
int n, k;
// 최소 비용 저장 변수 할당
int mn = 1000000000;
// 힌트 번들 구입 여부 재귀 함수 정의
void rc(vector<vector<int>> &c, vector<vector<int>> &h, int cst, int idx);

int solution(vector<vector<int>> cost, vector<vector<int>> hint)
{
    int answer = 0;
    // 스테이지 수 할당
    n = cost.size();
    // 힌트 번들에 들어 있는 힌트권 수 할당
    k = hint[0].size();
    // 재귀로 탐색
    rc(cost, hint, 0, 0);
    // 결과값 대입
    answer = mn;
    return answer;
}

void rc(vector<vector<int>> &c, vector<vector<int>> &h, int cst, int idx)
{
    // 모든 번들 탐색 완료 시 비용 계산
    if (idx == n - 1)
    {
        for (int i = 0; i < n; i++)
        {
            // 힌트권 수 할당
            int temp = cnt[i];
            // 힌트권 수가 최대 사용 가능 수보다 높으면 한계치까지만 사용
            if (temp > n - 1)
                temp = n - 1;
            cst += c[i][temp];
        }
        // 최소값 갱신
        if (mn > cst)
            mn = cst;
        return;
    }
    // 구입하지 않은 경우 다음 번들 확인
    rc(c, h, cst, idx + 1);
    // 힌트 번들 가격 할당
    int p = h[idx][0];
    // 스테이지 힌트권 보유 수 갱신
    for (int j = 1; j < k; j++)
        cnt[h[idx][j] - 1]++;
    // 구입 정보 갱신 후 다음 번들 확인
    rc(c, h, cst + p, idx + 1);
    // 스테이지 힌트권 보유 수 초기화
    for (int j = 1; j < k; j++)
        cnt[h[idx][j] - 1]--;
}
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    // 정렬을 위한 임시 변수 할당
    string s, sq;
    cin >> n >> s;
    // 임시 변수에 정렬할 문자열 대입
    sq = s;
    // 문자를 사전 기준 큰 순으로 정렬
    sort(sq.begin(), sq.end(), greater<>());
    // 뒤집어야 하는 범위 탐색
    for (int i = 0; i < n; i++)
        if (sq[i] != s[i])
        {
            // 정답 후보 문자열 저장 배열
            vector<pair<string, int>> ans;
            // 뒤집은 문자열 저장 변수
            string t = "";
            // 뒤집을 부분 문자열 할당
            for (int j = i; j < n; j++)
            {
                t += s[j];
                // 문자열 뒤집기
                reverse(t.begin(), t.end());
                // 정답 후보 배열에 저장
                ans.push_back({t, j});
                // 다음 뒤집기를 위해 다시 원상복구
                reverse(t.begin(), t.end());
            }
            // 정답 후보 배열 내림차순 정렬
            sort(ans.begin(), ans.end(), greater<>());
            // 뒤집을 범위 인덱스 할당
            int idx = ans[0].second;
            // 해당 범위만 뒤집어서 출력
            cout << s.substr(0, i) << ans[0].first << s.substr(idx + 1, n - 1 - idx);
            return 0;
        }
    // 입력받은 문자열이 내림차순이면 그대로 출력
    cout << s;
    return 0;
}
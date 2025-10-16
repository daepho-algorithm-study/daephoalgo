#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, num;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int ans = 0; // 정답 저장 변수
        cin >> n;
        vector<int> std(n + 1); // 학생들의 관계 저장 배열
        vector<int> deg(n + 1); // 진입 차수 저장 배열
        queue<int> q;           // 진입차수 0인 노드 저장 큐
        for (int j = 1; j <= n; j++)
        {
            cin >> std[j]; // 학생들이 선택한 번호 저장
            deg[std[j]]++; // 진입차수 표시
        }
        for (int j = 1; j <= n; j++)
            if (deg[j] == 0)
                q.push(j); // 진입차수가 0인 학생 큐에 삽입
        while (!q.empty())
        {
            int p = q.front(); // 학생 번호 할당
            ans++;             // 정답 수 증가
            q.pop();
            deg[std[p]]--; // 해당 학생 관계 제거
            if (deg[std[p]] == 0)
                q.push(std[p]); // 진입차수가 0이 된 학생 삽입
        }
        cout << ans << "\n";
    }
    return 0;
}
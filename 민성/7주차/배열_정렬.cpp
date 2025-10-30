#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

int A[9]; // A 원소 저장 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    vector<int> aseq(n + 1); // A 수열 순서 저장 배열
    aseq[0] = 0;             // 빈 공간 처리
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i]; // 배열 원소 저장
        aseq[i] = i; // 수열 초기 순서 저장
    }
    cin >> m;
    vector<tuple<int, int, int>> node(m); // 조작 비용 저장 배열
    for (int i = 0; i < m; i++)
    {
        int l, r, c;
        cin >> l >> r >> c;
        node[i] = {l, r, c}; // 조작 비용 저장
    }
    priority_queue<pair<int, vector<int>>> pq; // 다익스트라 구현 큐
    map<vector<int>, int> d;                   // 수열 비용 저장 맵
    pq.push({0, aseq});                        // 초기값 큐에 삽입
    d.insert({aseq, 0});                       // 맵에 초기값 저장
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        vector<int> seq = pq.top().second;
        pq.pop();
        if (cost != d[seq])
            continue;      // 갱신되지 않은 정보 제외
        bool check = true; // 정렬 여부 체크 변수
        for (int i = 1; i < n; i++)
            if (A[seq[i]] > A[seq[i + 1]])
            {
                check = false; // 정렬되지 않으면 체크 후 반복문 탈출
                break;
            }
        if (check)
        {
            cout << cost; // 정렬됬으면 해당 비용이 정답
            return 0;
        }
        for (int i = 0; i < m; i++)
        {
            vector<int> nxt = seq; // 다음 수열 할당
            // 조작 비용 할당
            int l = get<0>(node[i]), r = get<1>(node[i]), c = get<2>(node[i]);
            swap(nxt[l], nxt[r]); // 수열 순서 수정
            if (d.find(nxt) != d.end() && d[nxt] <= cost + c)
                continue;
            d[nxt] = cost + c;       // 비용 갱신
            pq.push({-d[nxt], nxt}); // 탐색을 위해 다시 큐에 삽입
        }
    }
    cout << -1;
    return 0;
}
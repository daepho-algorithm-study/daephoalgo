#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    // 팀 순위와 팀 수 저장 해시 할당
    unordered_map<string, int> rank, team;
    // 팀 순위 평균 저장 배열
    pair<double, string> avg[100];
    cin >> n;
    // 팀 순위와 팀 수 정보 저장
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        rank[s] += i;
        team[s]++;
    }
    // 팀 평균과 팀 이름 정보 저장
    int idx = 0;
    for (auto p : rank)
    {
        string k = p.first;
        int v = p.second;
        avg[idx++] = {1.0 * v / team[k], k};
    }
    // 팀 평균 기준 오름차순 정렬
    sort(avg, avg + idx);
    for (int i = 0; i < idx; i++)
        cout << avg[i].second << "\n";
    return 0;
}
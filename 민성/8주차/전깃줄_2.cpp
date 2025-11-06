#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 바이너리 서치 함수 정의
int bs(vector<pair<int, int>> &v, int s, int e, pair<int, int> x);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    cin >> n;
    // 전깃줄 정보 저장 배열과 증가 수열 저장 배열
    vector<pair<int, int>> elec(n), lis;
    vector<int> prev(n, -1);    // 복원을 위한 이전 좌표 저장 배열
    vector<int> keep(n, false); // 수열 구성 요소 체크 배열
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        elec[i] = {a, b}; // 전깃줄 정보 저장
    }
    sort(elec.begin(), elec.end());     // A전봇대 기준 정렬
    lis.push_back({elec[0].second, 0}); // 초기값 할당
    for (int i = 1; i < n; i++)
    {
        int e = lis.size() - 1; // 수열 끝 좌표 할당
        // 증가 수열 끝보다 큰 수면 수열에 삽입
        if (lis[e].first < elec[i].second)
        {
            lis.push_back({elec[i].second, i});
            prev[i] = lis[e].second;
        }
        else
        {
            int p = bs(lis, 0, e, {elec[i].second, i}); // 삽입 위치 할당
            if (p > 0)
                // 해당 위치 바로 앞 수의 원본 좌표 저장
                prev[i] = lis[p - 1].second;
        }
    }
    int l = lis.size();          // 수열의 최대 길이 할당
    int idx = lis.back().second; // 복원 좌표 할당
    while (idx != -1)
    {
        keep[idx] = true; // 수열에 해당하는 좌표 체크
        idx = prev[idx];  // 다음 복원 좌표 할당
    }
    cout << n - l << "\n"; // 수열에 포함되지 못한 좌표 개수 출력
    for (int i = 0; i < n; i++)
        if (!keep[i])
            cout << elec[i].first << "\n"; // 수열에 해당하지 않는 좌표 출력
    return 0;
}

int bs(vector<pair<int, int>> &v, int s, int e, pair<int, int> x)
{
    while (s < e)
    {
        int m = (s + e) / 2;
        if (v[m].first >= x.first)
            e = m; // 왼쪽 이분 탐색
        else
            s = m + 1; // 오른쪽 이분 탐색
    }
    v[s] = x; // 목적지에 값 삽입
    return s; // 삽입 좌표 리턴
}
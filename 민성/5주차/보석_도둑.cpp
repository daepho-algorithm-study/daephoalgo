#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> jewel[300000]; // 보석 정보 저장 배열
int bag[300000];              // 가방 허용 무게 저장 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, m, v, idx = 0;   // 현재 탐색 보석 번호 저장 변수
    int long long sm = 0;      // 보석 가격 합산 변수
    priority_queue<int> value; // 보석 가격 임시 저장 우선순위 큐
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> m >> v;
        jewel[i] = {m, v}; // 보석 정보 저장
    }
    for (int i = 0; i < k; i++)
        cin >> bag[i];      // 가방 허용 무게 저장
    sort(jewel, jewel + n); // 오름차순으로 보석 무게와 가격 정렬
    sort(bag, bag + k);     // 오름차순으로 가방 허용 무게 정렬
    for (int i = 0; i < k; i++)
    {
        // 현재 가방에 들어갈 수 있는 보석 큐에 삽입
        while (idx < n && jewel[idx].first <= bag[i])
        {
            value.push(jewel[idx].second);
            idx++;
        }
        // 해당 가방에 들어갈 수 있는 가장 비싼 보석 합산
        if (!value.empty())
        {
            sm += value.top();
            value.pop();
        }
    }
    cout << sm;
    return 0;
}
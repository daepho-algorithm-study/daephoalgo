#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> city; // 각 도시의 홍보 비용과 고객 수 저장 배열
int customer[1101];          // 해당 고객 수를 확보하기 위한 최소 비용 저장 DP 배열
int INF = 1000000;           // 초기화 변수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c, n, cost, p, mn = INF; // 최소 비용 저장 변수
    cin >> c >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cost >> p;
        city.push_back({cost, p}); // 각 도시의 홍보 비용과 고객 수 저장
    }
    for (int i = 1; i <= 1100; i++)
        customer[i] = INF; // 배열 초기화
    for (int i = 1; i <= 1100; i++)
        for (int j = 0; j < n; j++)
        {
            cost = city[j].first, p = city[j].second; // 홍보 비용과 고객 수를 할당
            if (i - p >= 0 && customer[i] > customer[i - p] + cost)
                customer[i] = customer[i - p] + cost; // 해당 고객 수 최소 비용으로 갱신
        }
    for (int i = c; i <= 1100; i++)
        if (mn > customer[i])
            mn = customer[i]; // 최소 비용 갱신
    cout << mn;
    return 0;
}
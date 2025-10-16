#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int pA[1001], pB[1001];           // 누적합 저장 배열
vector<int> sA;                   // A 부 배열합 저장 배열
unordered_map<int, long long> sB; // B 부 배열합 저장 해시

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, m, num;
    long long cnt = 0; // 경우의 수 카운팅 변수
    cin >> t >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        pA[i] = num + pA[i - 1]; // A 배열 누적합 저장
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> num;
        pB[i] = num + pB[i - 1]; // B 배열 누적합 저장
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
        {
            int sub = pA[i] - pA[j];
            sA.push_back(sub); // A 배열의 부 배열합 저장
        }
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < i; j++)
        {
            int sub = pB[i] - pB[j];
            sB[sub]++; // B 배열의 부 배열합 개수 저장
        }
    for (int i = 0; i < sA.size(); i++)
        cnt += sB[t - sA[i]];
    cout << cnt;
    return 0;
}
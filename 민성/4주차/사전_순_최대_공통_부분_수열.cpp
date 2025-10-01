#include <iostream>
#include <vector>

using namespace std;

int a[100], b[100]; // 수열 A, B 저장 배열
vector<int> com;    // 정답 수열 저장 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i]; // 수열 A 저장
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];    // 수열 B 저장
    int sa = 0, sb = 0; // 탐색 시작 위치 저장 변수
    for (int k = 100; k > 0; k--)
    {
        int x = -1, y = -1; // 각 수열에 k 위치 저장 변수
        for (int i = sa; i < n; i++)
            if (k == a[i])
            {
                x = i; // 수열 A에 k가 존재하면 위치 저장 후 탐색 종료
                break;
            }
        for (int i = sb; i < m; i++)
            if (k == b[i])
            {
                y = i; // 수열 B에 k가 존재하면 위치 저장 후 탐색 종료
                break;
            }
        if (x == -1 || y == -1)
            continue;           // 두 수열 중 한 곳에라도 없으면 스킵
        sa = x + 1, sb = y + 1; // 탐색 시작 위치 갱신
        com.push_back(k);       // k 수열에 저장
        k++;                    // 중복 수 고려
    }
    cout << com.size() << "\n";
    for (int i = 0; i < com.size(); i++)
        cout << com[i] << " ";
    return 0;
}
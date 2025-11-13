#include <iostream>

using namespace std;

bool bridge[301][301]; // 구름다리 연결 여부 저장 배열
int degree[301];       // 다리 연결 개수 저장 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b, k, r;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        // 구름다리 연결관계 저장
        bridge[a][b] = true, bridge[b][a] = true;
        degree[a]++, degree[b]++;
    }
    if (n <= 4)
    {
        r = 1;                     // n(n-1)/2 가 2(n-1)보다 작거나 같은 경우
        k = (n - 1) * (n - 2) / 2; // n(n-1)/2 - (n-1)
        cout << k << "\n"
             << r << "\n";
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                if (!bridge[i][j]) // 연결 안 된 다리 출력
                    cout << i << " " << j << "\n";
    }
    else
    {
        r = 2;               // 나머지 경우
        int mx = 0, idx = 0; // 가장 높은 차수의 값과 번호 저장 변수
        for (int i = 1; i <= n; i++)
            if (degree[i] > mx)
            {
                mx = degree[i]; // 가장 높은 차수의 값과 번호 저장
                idx = i;
            }
        k = n - 1 - mx; // (n-1)개 만큼 연결해야 하므로 최대 차수만큼 차감
        cout << k << "\n"
             << r << "\n";
        for (int i = 1; i <= n; i++)
            if (idx != i && !bridge[idx][i]) // 연결 안 된 다리 출력
                cout << idx << " " << i << "\n";
    }
    return 0;
}
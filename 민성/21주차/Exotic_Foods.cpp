#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 음식 가치 저장 배열
int vi[50000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, n;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> n;
        // 누적 가치 저장 배열 할당
        vector<int> sm(n);
        // 음식 가치 정보 저장
        for (int j = 0; j < n; j++)
            cin >> vi[j];
        // 초기값 할당
        sm[0] = vi[0];
        sm[1] = vi[1];
        sm[2] = vi[0] + vi[2];
        // 조건에 맞게 누적
        for (int j = 3; j < n; j++)
            sm[j] = max(sm[j - 3], sm[j - 2]) + vi[j];
        // 최대 누적값 할당
        int mx = max(sm[n - 2], sm[n - 1]);
        cout << "Data Set " << i << ":\n"
             << mx << "\n\n";
    }
    return 0;
}
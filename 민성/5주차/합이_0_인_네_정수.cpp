#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long ans = 0; // 정답 저장 변수
    cin >> n;
    vector<int> A(n), B(n), C(n), D(n); // 각 배열 할당
    for (int i = 0; i < n; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i]; // 배열 정수값 저장
    vector<int> AB, CD;                      // 병합 배열 할당
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            AB.push_back(A[i] + B[j]); // 배열 병합
            CD.push_back(C[i] + D[j]);
        }
    sort(AB.begin(), AB.end()); // 병합 배열 정렬
    sort(CD.begin(), CD.end());
    int s = 0, e = CD.size() - 1; // 투 포인터 변수 할당
    while (s < AB.size() && e >= 0)
    {
        int sm = AB[s] + CD[e]; // 두 병합 배열 합 저장
        if (sm < 0)
            s++;
        else if (sm > 0)
            e--;
        else
        {
            int cs = 1, ce = 1; // 같은 수 카운팅 변수 할당
            while (s < AB.size() - 1 && AB[s] == AB[s + 1])
                cs++, s++; // AB 배열에 동수 카운팅 및 동수 탐색
            while (e > 0 && CD[e] == CD[e - 1])
                ce++, e--;  // CD 배열에 동수 카운팅 및 동수 탐색
            ans += 1LL * cs * ce; // 합이 0인 수의 개수 카운팅
            s++;            // 다음 수 탐색
        }
    }
    cout << ans;
    return 0;
}
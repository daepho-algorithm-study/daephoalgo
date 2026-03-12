#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

// 다이스 면 개수 저장 배열
pair<int, int> a[1000];
// 다이스 구성 면 저장 배열
vector<vector<int>> v(1000);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 소수점 5자리로 고정
    cout << fixed;
    cout.precision(5);
    // 다이스 면 총합 저장 변수
    int n, m = 0;
    // 기대값 저장 변수
    double e = 0;
    cin >> n;
    // 다이스 면과 순서, 총합 저장
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
        m += a[i].first;
    }
    // 다이스 면 개수 오름차순 정렬
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        // 해당 다이스 면 개수와 순서 할당
        int sp = a[i].first, idx = a[i].second, sm = 0;
        // 면 개수만큼 내림차순으로 숫자 할당
        for (int i = 0; i < sp; i++)
        {
            sm += m;
            v[idx].push_back(m);
            m--;
        }
        // 기대값 합산
        e += 1.0 * sm / sp;
    }
    cout << e << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
#include <iostream>

using namespace std;

int l[10001], r[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, k, num;
    cin >> x >> k;
    // 왼쪽 오른쪽 양말 번호별 개수 입력
    for (int i = 0; i < x; i++)
    {
        cin >> num;
        l[num]++;
    }
    for (int i = 0; i < x; i++)
    {
        cin >> num;
        r[num]++;
    }
    // 경우의 수 저장 변수
    long long sm = 0;
    // 왼쪽 양말 번호와 다른 번호의 오른쪽 양말 수 곱을 합산
    for (int i = 1; i <= k; i++)
        sm += 1LL * l[i] * (x - r[i]);
    cout << sm;
    return 0;
}
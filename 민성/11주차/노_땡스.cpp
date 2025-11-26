#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int card[33];        // 카드 수 저장 배열
    int n, temp, sm = 0; // 점수 합 저장 변수
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> card[i]; // 카드 수 저장
    temp = card[0];     // 그룹 초기값 할당
    for (int i = 1; i < n; i++)
        if (card[i] != card[i - 1] + 1)
        {
            sm += temp;     // 그룹 점수 합산
            temp = card[i]; // 새 그룹 점수 할당
        }
    sm += temp; // 마지막 그룹 점수도 합산
    cout << sm;
    return 0;
}
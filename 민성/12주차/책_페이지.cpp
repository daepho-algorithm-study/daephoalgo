#include <iostream>

using namespace std;

int cnt[10]; // 각 숫자 등장 횟수 저장 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, extra = 0; // 이전 나머지 파트 저장 변수
    cin >> n;
    for (int i = 1; n != 0; i *= 10)
    {
        int mod = n % 10; // 나머지 저장
        n /= 10;          // 해당 자릿수 반복 횟수
        // 해당 자릿수의 길이만큼의 수는 0을 제외해야 함
        // ex) 십의 자릿수에서 01, 02 등은 제외
        cnt[0] -= i;
        for (int j = 0; j < mod; j++)
            cnt[j] += (n + 1) * i; // 해당 자릿수의 수보다 작은 수는 +1 추가
        // 해당 자릿수의 수는 아래 자릿수 나머지만큼만 추가
        cnt[mod] += n * i + 1 + extra;
        for (int j = mod + 1; j <= 9; j++)
            cnt[j] += n * i; // 해당 자릿수의 수보다 크면 n만 곱셈
        extra += mod * i;     // 해당 자릿수의 나머지 파트 저장
    }
    for (int i = 0; i <= 9; i++)
        cout << cnt[i] << " ";
    return 0;
}
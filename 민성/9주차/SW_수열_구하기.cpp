#include <iostream>

using namespace std;

int sw[5000]; // SW 수열 저장 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n / 2; i++)
    {
        // 1부터 N까지의 수를 나열해서 왼쪽 오른쪽을 번갈아가며 삽입
        sw[i * 2] = i + 1;
        sw[i * 2 + 1] = n - i;
    }
    if (n % 2 == 1)
        sw[n - 1] = n / 2 + 1; // 홀수일 때 마지막 수 처리
    for (int i = 0; i < n; i++)
        cout << sw[i] << " ";
    return 0;
}
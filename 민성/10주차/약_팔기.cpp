#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << 2000 << "\n"; // k 값 출력
    for (int i = 0; i < 1000; i++)
        cout << 1 << " ";
    for (int i = 0; i < 1000; i++) // 1과 1000을 1000개씩 출력
        cout << 1000 << " ";
    return 0;
}
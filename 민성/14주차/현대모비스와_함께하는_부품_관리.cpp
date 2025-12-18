#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // 부품 관리 문구 출력
        cout << "Material Management " << i << "\n";
        // 프로그램 완료 문구 출력
        cout << "Classification ---- End!" << "\n";
    }
    return 0;
}
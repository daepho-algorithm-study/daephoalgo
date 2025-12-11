#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int temp, mn = 201; // 최소 온도 저장 변수
    string city, ans;   // 정답 저장 변수
    while (1)
    {
        cin >> city >> temp;
        if (temp < mn)
        {
            mn = temp; // 최소값 갱신
            ans = city;
        }
        if (city == "Waterloo")
            break;
    }
    cout << ans;
    return 0;
}
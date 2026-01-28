#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string s;
    double w1, w2, b;
    cin >> t;
    while (t--)
    {
        cin >> s >> w1 >> w2 >> b;
        // 입력이 11, 10, 01, 00일 때 결과값 저장 변수
        double oo = w1 + w2 + b, oz = w1 + b, zo = w2 + b, zz = b;
        // AND 연산 만족 확인
        if (s == "AND")
        {
            if (oo >= 0 && oz < 0 && zo < 0 && zz < 0)
                cout << "true";
            else
                cout << "false";
            cout << "\n";
        }
        // OR 연산 만족 확인
        else
        {
            if (oo >= 0 && oz >= 0 && zo >= 0 && zz < 0)
                cout << "true";
            else
                cout << "false";
            cout << "\n";
        }
    }
    return 0;
}
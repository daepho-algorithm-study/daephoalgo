#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 정수형 A, B 저장 변수
    long long a, b;
    // 이진수 변환 A, B 저장 변수 할당
    bitset<64> ba, bb;
    // 앞 쪽 동일 비트 저장 문자열과 A, B 비트 문자열 변수 할당
    string f = "", sa, sb;
    // 비트가 다른 위치 저장
    int idx;
    cin >> a >> b;
    // 정수형 이진수로 변환
    ba = a, bb = b;
    for (int i = ba.size() - 1; i >= 0 ; i--)
    {
        // 비트가 동일한 부분 저장
        if (ba[i] == bb[i])
            f += to_string(ba[i]);
        // 비트가 달라진 위치 저장 후 반복 종료
        else
        {
            idx = i;
            break;
        }
    }
    // 동일 비트 부분 삽입 후 다른 비트가 나온 부분 삽입
    sa = f + "0", sb = f + "1";
    // 비트가 다른 위치 다음부터 A는 1로, B는 0으로 채우기
    for (int i = idx - 1; i >= 0; i--)
    {
        sa += "1";
        sb += "0";
    }
    // 문자열을 이진수로 변환 후 다시 정수형으로 변환
    bitset<64> bx(sa), by(sb);
    unsigned long long x = bx.to_ullong(), y = by.to_ullong();
    cout << x << " " << y;
    return 0;
}
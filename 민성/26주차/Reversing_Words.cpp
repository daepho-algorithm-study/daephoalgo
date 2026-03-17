#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 대문자, 소문자 및 기호 구분 배열
int check[80];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while (1)
    {
        getline(cin, s);
        // 입력으로 "#"이 들어오면 반복 종료
        if (s == "#")
            break;
        // 문자열 길이 저장 및 뒤집을 위치 변수 할당
        int ss = s.size(), p = 0;
        // 뒤집을 문자열 저장 스택
        stack<char> v;
        for (int i = 0; i < ss; i++)
        {
            // 문자열 입력 시 대소문자 체크 후 소문자로 스택에 삽입
            if (s[i] >= 65 && s[i] <= 90)
            {
                check[i] = 1;
                v.push(s[i] + 32);
            }
            else if (s[i] >= 97 && s[i] <= 122)
            {
                check[i] = -1;
                v.push(s[i]);
            }
            // 기호 입력 시 체크만
            else if (s[i] != 32)
                check[i] = 0;
            // 공백 입력 시 뒤집은 문자열 출력
            else
            {
                for (int j = p; j < i; j++)
                {
                    // 기호는 원래 자리 그대로 출력
                    if (check[j] == 0)
                        cout << s[j];
                    // 위치에 맞게 대소문자를 출력
                    else
                    {
                        if (check[j] == 1)
                        {
                            char temp = v.top() - 32;
                            cout << temp;
                        }
                        else
                            cout << v.top();
                        v.pop();
                    }
                }
                // 공백 출력 후 위치 변수 갱신
                cout << " ";
                p = i + 1;
            }
        }
        // 스택에 남은 나머지도 출력
        for (int j = p; j < ss; j++)
        {
            if (check[j] == 0)
                cout << s[j];
            else
            {
                if (check[j] == 1)
                {
                    char temp = v.top() - 32;
                    cout << temp;
                }
                else
                    cout << v.top();
                v.pop();
            }
        }
        cout << "\n";
    }
    return 0;
}
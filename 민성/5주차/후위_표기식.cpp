#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<char> post;                             // 후위 표기를 위한 배열
char sign[6] = {'+', '-', '*', '/', '(', ')'}; // 연산 기호 저장 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
            cout << s[i]; // 알파벳이면 바로 출력
        else
        {
            // 연산부호가 '+' 나 '-' 면
            if (s[i] == sign[0] || s[i] == sign[1])
            {
                while (!post.empty() && post.back() != sign[4])
                {
                    cout << post.back();
                    post.pop_back(); // 왼괄호를 만나거나 스택이 빌 때까지 pop
                }
                post.push_back(s[i]); // 그 후 삽입
            }
            // 연산부호가 '*' 나 '/' 면
            else if (s[i] == sign[2] || s[i] == sign[3])
            {
                while (!post.empty() && (post.back() == sign[2] || post.back() == sign[3]))
                {
                    cout << post.back();
                    post.pop_back(); // '*' 와 '/'를 제외한 다른 연산 부호를 만날 때까지 pop
                }
                post.push_back(s[i]); // 그 후 삽입
            }
            else if (s[i] == sign[5]) // 오른 괄호면
            {
                while (post.back() != sign[4])
                {
                    cout << post.back();
                    post.pop_back();
                }
                post.pop_back(); // 괄호 후에 들어온 모든 연산 출력
            }
            else
                post.push_back(s[i]); // 왼괄호는 바로 삽입
        }
    }
    while (!post.empty())
    {
        cout << post.back();
        post.pop_back(); // 스택에 남은 연산 출력
    }
    return 0;
}